<?php
/**
 * @file
 *
 * Implementation of the block display of a user's notes for each article
 */

/**
 * Implements hook_block_info()
 *
 * Defines a block only visible on pages of content type 'article'
 * And a block for displaying site statistics
 */
function jdt_user_notes_block_info() {
  $blocks['notes'] = array(
    'info' => t('Display Notes'),
    'cache' => DRUPAL_CACHE_PER_USER,
    'status' => 1,
    'region' => 'sidebar_first',
    'visibility' => BLOCK_VISIBILITY_PHP,
    // Ugly code to only display block if the user has permission and the page is an article
    'pages' => "<?php
                  if (arg(0) == 'node' && is_numeric(arg(1))) { 
                    if (user_access('note')) {
                      if (node_load(arg(1))->type == 'article') {
                        return TRUE;
                      }
                    }
                  } 
                  return FALSE; 
                ?>"
  );

  $blocks['statistics'] = array(
    'info' => t('Site Statistics'),
    'cache' => DRUPAL_CACHE_PER_ROLE,
    'status' => 1,
  );

  return $blocks;
}

/**
 * Implements hook_block_view()
 */
function jdt_user_notes_block_view($delta = '') {
  switch ($delta) {
    case 'notes' :
      $block['subject'] = t('Notes for this article:');
      $block['content'] = drupal_get_form('jdt_user_notes_article_form', arg(1));
      break;

    case 'statistics' :
      $block['subject'] = t('Site Statistics');
      $block['content'] = site_statistics_content();
  }
  return $block;
}

function site_statistics_content() {
  $articles = db_select('node')
    ->condition('type', 'article', '=')
    ->countQuery()
    ->execute()
    ->fetchField();

  $notes = db_select('jdt_user_notes')
    ->countQuery()
    ->execute()
    ->fetchField();

  $users = db_select('users')
    ->countQuery()
    ->execute()
    ->fetchField();

  $content = array(
    '#items' => array(
      'Number of Articles: ' . $articles,
      'Number of Notes: ' . $notes,
      'Number of Users: ' . ($users - 1)
    ),
    '#theme' => 'item_list'
  );
  return $content;
}

/**
 * Implements hook_form()
 *
 * Displays all notes created by user for the current article
 * Selecting a note will allow it to be edited
 */
function jdt_user_notes_article_form($form, &$form_state, $nid) {
  global $user;
  $uid = $user->uid;
  $notes = get_article_notes($uid, $nid);

  $options = array();
  foreach ($notes as $note) {
    $options[$note->note_id] = array('note' => $note->note_text, 'note_id' => $note->note_id);
  }

  if (count($options) > 0) {
    $form['table'] = array(
      '#type' => 'tableselect',
      '#multiple' => FALSE,
      '#header' => array('note' => t('Note')),
      '#options' => $options
    );
   
    // Selecting this button will link to a new page of the form where you can update the note
    $form['update_note'] = array(
      '#type' => 'submit',
      '#value' => t('Edit selected note'),
      '#submit' => array('jdt_user_notes_article_form_submit'),
    );
  }
  else {
    $form['alert'] = array(
      '#type' => 'item',
      '#description' => "You currently don't have any notes for this article!"
    );
  }

  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid
  );

  // Selecting this button will link to a new form for creating a note.
  // Should this even be in this form?
  $form['new_note'] = array(
    '#type' => 'submit',
    '#value' => t('Create new note'),
    '#submit' => array('jdt_user_notes_article_form_new')
  );

  return $form;
}

/**
 * Implements hook_form_submit()
 *
 * Submit handler to create a new note.
 * Links to specified menu
 */
function jdt_user_notes_article_form_new($form, &$form_state) {
  $form_state['redirect'] = 'node/' . $form_state['values']['nid'] . '/create_note';
}

 /**
  * Implements hook_form_submit()
  *
  * Submit handler to update an existing note
  * Links to specified menu
  */
function jdt_user_notes_article_form_submit($form, &$form_state) {
  $form_state['redirect'] = 'node/' . $form_state['values']['nid'] . '/' . $form_state['values']['table'];
}
