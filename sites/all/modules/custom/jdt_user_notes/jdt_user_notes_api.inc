<?php

/**
 * Return the text of the note with this id
 */
function get_note($nid) {
   $query = db_select('jdt_user_notes');
       $query->Fields('jdt_user_notes', array('note_text'));
       $query->condition('note_id', $nid);
   return $query->execute();
}

/**
 * Create a new note
 */
function new_note($nid, $uid, $text) {
    $query = db_insert('jdt_user_notes');
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
   $query = db_delete('jdt_user_notes');
       $query->condition('note_id', $nid);
       $query->execute();
    }
