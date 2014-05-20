<?php

/**
 * Implements hook_block_info()
 *
 * Defines a block only visible on pages of content type 'article'
 */
function jdt_user_notes_block_info() {
  $blocks['notes'] = array(
    'info' => t('Display Notes'),
    'cache' => DRUPAL_CACHE_PER_USER,
    'region' => 'sidebar_first',
    // @TODO Should default to only be viewable on articles, in the sidebar, by authenticated users
    /*'visibitlity' => BLOCK_VISIBILITY_PHP,
    'pages' => "<?php  
                  if (arg(0) == 'node' && is_numeric(arg(1)) { 
                    $node = node_load(array(arg(1)));
                    if ($node -> type == 'article') {
                      return TRUE;
                    }
                  } 
                  return FALSE; ?>"*/
  );
  return $blocks;
}

/**
 * Implements hook_block_view()
 */
function jdt_user_notes_block_view($delta = '') {
  switch($delta) {
    case 'notes' :
      $block['subject'] = t('Notes for this article:');
      $block['content'] = drupal_get_form('jdt_user_notes_article_form', arg(1));
      break;
  }
  return $block;
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

  $form['table'] = array(
    '#type' => 'tableselect',
    '#multiple' => FALSE,
    '#header' => array('note' => t('Note')),
    '#options' => $options
  );
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid
  );

  // Selecting this button will link to a new page of the form where you can update the note
  $form['new_note'] = array(
    '#type' => 'submit',
    '#value' => t('Edit selected note'),
    '#submit' => array('jdt_user_notes_article_form_submit'),
  );

  // Selecting this button will link to a new form for creating a note.
  // Should this even be in this form?
  $form['update_note'] = array(
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
  drupal_goto('node/' . $form_state['values']['nid'] . '/create_note');
}
 /**
  * Implements hook_form_submit()
  *
  * Submit handler to update an existing note
  * Links to specified menu
  */
function jdt_user_notes_article_form_submit($form, &$form_state) {
  drupal_goto('node/' . $form_state['values']['nid'] . '/' . $form_state['values']['table']);
}