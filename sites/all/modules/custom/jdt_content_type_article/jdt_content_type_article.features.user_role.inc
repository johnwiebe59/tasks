<?php
/**
 * @file
 * jdt_content_type_article.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function jdt_content_type_article_user_default_roles() {
  $roles = array();

  // Exported role: administrator.
  $roles['administrator'] = array(
    'name' => 'administrator',
    'weight' => 2,
  );

  return $roles;
}
