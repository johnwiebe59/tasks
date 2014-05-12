<?php

/**
 * @file
 * The jdt_user_notes database api
 *
 * Provides setters and getters for the jdt_user_notes database table
 */

// Maybe I should have an exists function?

/**
 * Return the text of the note with this id
 */
function get_note($uid, $nid) {
  $conditions = db_and()
    ->condition('author_uid', $uid, '=')
    ->condition('article_nid', $nid, '=');
  return db_select('jdt_user_notes')
    ->fields('jdt_user_notes', array('note_text'))
    ->condition($conditions)
    ->execute();
}

/**
 * Create a new note
 */
function new_note($nid, $uid, $text) {
  db_insert('jdt_user_notes')
    ->fields(array(
      'article_nid' => $nid,
      'author_uid' => $uid,
      'note_text' => $text
    ))
    ->execute();
}

/**
 * Delete an existing note
 */
function delete_note($uid, $nid) {
  $conditions = db_and()
    ->condition('author_uid', $uid, '=')
    ->condition('article_nid', $nid, '=');
  db_delete('jdt_user_notes')
    ->condition($conditions)
    ->execute();
}

/**
 * Update an existing note
 */
function update_note($uid, $nid, $text) {
  $conditions = db_and()
    ->condition('author_uid', $uid, '=')
    ->condition('article_nid', $nid, '=');
  db_update('jdt_user_notes')
    ->fields(array(
      'note_text' => $text
    ))
    ->condition($conditions)
    ->execute();
}
