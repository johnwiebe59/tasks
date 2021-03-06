<?php

/**
 * @file
 * The jdt_user_notes database api
 *
 * Provides setters and getters for the jdt_user_notes database table
 */

/**
 * Return the text of the note with this id
 */
function get_note($note_id) {
  return db_select('jdt_user_notes')
    ->fields('jdt_user_notes', array('article_nid', 'note_text'))
    ->condition('note_id', $note_id, '=')
    ->execute();
}

/**
 * Get notes for current article made by the current user
 */
function get_article_notes($uid, $nid) {
  $conditions = db_and()
    ->condition('author_uid', $uid, '=')
    ->condition('article_nid', $nid, '=');
  return db_select('jdt_user_notes')
    ->fields('jdt_user_notes', array('note_id', 'note_text'))
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
 * Update an existing note
 */
function update_note($note_id, $text) {
  db_update('jdt_user_notes')
    ->fields(array(
      'note_text' => $text
    ))
    ->condition('note_id', $note_id, '=')
    ->execute();
}
