<?php

/**
 * Return the text of the note with this id
 */
function get_note($nid) {
   $query = db_select('jdt_users_notes');
       $query->Fields('jdt_users_notes', array('note_text'));
       $query->condition('note_id', $nid);
   return = $query->execute();
}

/**
 * Create a new note
 */
function new_note($nid, $uid, $text) {
    $query = db_insert('jdt_users_notes');
        $query->fields(array(               // Do I need to do something with the serial?
            'article_nid' => $nid,
            'author_uid' => $uid,
            'note_text' => $text
        ));
        $query->execute();
}

/**
 * Delete an existing note
 */
function delete_note($uid, $nid) {
   $query = db_delete('jdt_users_notes');
       $query->condition('note_id', $nid);
       $query->execute();
