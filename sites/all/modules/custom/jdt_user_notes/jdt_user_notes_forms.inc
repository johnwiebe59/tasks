<?php
/**
 * @file
 *
 * Contains the various forms used by the module
 */

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
   
    // Button to update the selected, existing note
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

  // Store the node_id
  $form['nid'] = array(
    '#type' => 'hidden',
    '#value' => $nid
  );

  $form['new'] = array(
    '#markup' => l('Create a New Note', 'node/' . $nid . '/nojs/create_note', array('attributes' => array('class' => 'ctools-use-modal')))
  );

  // Button to create a new note
  // Make this jsut a button.
  $form['new_note'] = array(
    '#type' => 'submit',
    '#value' => t('Create new note'),
    '#attributes' => array(
      'class' => array('ctools-use-modal')
    )
  );

  $form['#action'] = url('node/' . $nid . '/nojs/create_note');
  return $form;
}

 /**
  * Implements hook_form_submit()
  *
  * Submit handler to update an existing note
  * Links to specified menu
  */
function jdt_user_notes_article_form_submit($form, &$form_state) {
  //$form_state['redirect'] = 'node/' . $form_state['values']['nid'] . '/' . $form_state['values']['table'];
}

// ------------------------------------------------------------------------------------------------------------

/**
 * Implements hook_form()
 *
 * Creates a custom form for entering the text for a new note
 */
function jdt_user_notes_new_form($form, &$form_state, $nid) {
    $form['description'] = array(
        '#type' => 'item',
        '#title' => t('Enter the text for your new note')
    );
    
    // If the form is opened in a modal, the node_id will already be in the form state and $nid will be NULL
    if ($nid == NULL) {
      $nid = $form_state['nid'];
    }

    $form['nid'] = array(
        '#type' => 'hidden',
        '#value' => $nid
    );


    $form['note'] = array(
        '#type' => 'textarea',
        '#title' => t('Note'),
        '#required' => TRUE
    );

    $form['submit'] = array(
        '#type' => 'submit',
        '#value' => 'Submit'
    );

    return $form;
}

/**
 * Implements hook_submit()
 *
 * Submit the note information entered in form to database to create a new note
 */
function jdt_user_notes_new_form_submit($form, &$form_state) {
    global $user;
    new_note($form_state['values']['nid'], $user->uid, $form_state['values']['note']);
}

// ------------------------------------------------------------------------------------------------------------

/**
 * Implements hook_form()
 *
 * Edit the text of an existing note
 */
function jdt_user_notes_update_form($form, &$form_state, $nid, $note_id) {
    $note = get_note($note_id);

    $form['description'] = array(
        '#type' => 'item',
        '#title' => t('Edit an existing note')
    );

    $form['note_text'] = array(
        '#type' => 'textarea',
        '#title' => t('Note'),
        '#default_value' => $note->fetch()->note_text,
        '#required' => TRUE
    );

    $form['note_id'] = array(
        '#type' => 'hidden',
        '#value' => $note_id
    );

    $form['nid'] = array(
        '#type' => 'hidden',
        '#value' => $nid
    );
}

/**
 * Implements hook_submit()
 *
 * Will update the text of the note in the database
 */
function jdt_user_notes_update_form_submit($form, &$form_state) {
    update_note($form_state['values']['note_id'], $form_state['values']['note_text']);
    $form_state['redirect'] = 'node/' . $form_state['values']['nid'];
}
