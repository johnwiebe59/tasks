<?php
/**
 * @file
 * jdt_content_type_article.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function jdt_content_type_article_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'panel';
  $page->task = 'page';
  $page->admin_title = 'Panel';
  $page->admin_description = '';
  $page->path = 'panel';
  $page->access = array();
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Panel',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_panel_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'panel';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(
      0 => array(
        'identifier' => 'User',
        'keyword' => 'user',
        'name' => 'user',
        'type' => 'current',
        'uid' => '',
        'id' => 1,
      ),
    ),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 1,
          1 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => '30.00618196483749',
        'width_type' => '%',
        'children' => array(
          0 => 'main-row',
          1 => 3,
        ),
        'parent' => 'canvas',
      ),
      'main-row' => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'center',
          1 => 'region_right',
        ),
        'parent' => 'main',
      ),
      'center' => array(
        'type' => 'region',
        'title' => 'Column 2',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
      1 => array(
        'type' => 'column',
        'width' => '69.9938180351625',
        'width_type' => '%',
        'parent' => 'canvas',
        'children' => array(
          0 => 2,
        ),
        'class' => '',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'sidebar',
        ),
        'parent' => '1',
        'class' => '',
      ),
      'sidebar' => array(
        'type' => 'region',
        'title' => 'Column 1',
        'width' => 100,
        'width_type' => '%',
        'parent' => '2',
        'class' => '',
      ),
      3 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'column_2___bottom',
        ),
        'parent' => 'main',
        'class' => '',
      ),
      'column_2___bottom' => array(
        'type' => 'region',
        'title' => 'Column 2 - bottom',
        'width' => 100,
        'width_type' => '%',
        'parent' => '3',
        'class' => '',
      ),
      'region_right' => array(
        'type' => 'region',
        'title' => 'Column 2 right',
        'width' => 50,
        'width_type' => '%',
        'parent' => 'main-row',
        'class' => '',
      ),
    ),
  );
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar' => NULL,
      'column_2___bottom' => NULL,
      'region_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '00e6b743-eabb-48a2-bb32-10fde3539d77';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-2864e708-758a-461b-96fa-51b05ea42e4f';
    $pane->panel = 'center';
    $pane->type = 'token';
    $pane->subtype = 'user:uid';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'context_user_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2864e708-758a-461b-96fa-51b05ea42e4f';
    $display->content['new-2864e708-758a-461b-96fa-51b05ea42e4f'] = $pane;
    $display->panels['center'][0] = 'new-2864e708-758a-461b-96fa-51b05ea42e4f';
    $pane = new stdClass();
    $pane->pid = 'new-16f1d904-0ca7-47fd-8db7-f9f5cedd8e3b';
    $pane->panel = 'column_2___bottom';
    $pane->type = 'block';
    $pane->subtype = 'user-new';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '16f1d904-0ca7-47fd-8db7-f9f5cedd8e3b';
    $display->content['new-16f1d904-0ca7-47fd-8db7-f9f5cedd8e3b'] = $pane;
    $display->panels['column_2___bottom'][0] = 'new-16f1d904-0ca7-47fd-8db7-f9f5cedd8e3b';
    $pane = new stdClass();
    $pane->pid = 'new-bb9c3f91-21fe-44d6-b2e8-e93cde282582';
    $pane->panel = 'column_2___bottom';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => 'lorem',
      'title' => 'Lorem',
      'body' => 'Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur, adipisci velit, sed quia non numquam eius modi tempora incidunt ut labore et dolore magnam aliquam quaerat voluptatem. Ut enim ad minima veniam, quis nostrum exercitationem ullam corporis suscipit laboriosam, nisi ut aliquid ex ea commodi consequatur? Quis autem vel eum iure reprehenderit qui in ea voluptate velit esse quam nihil molestiae consequatur, vel illum qui dolorem eum fugiat quo voluptas nulla pariatur?',
      'format' => 'filtered_html',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'bb9c3f91-21fe-44d6-b2e8-e93cde282582';
    $display->content['new-bb9c3f91-21fe-44d6-b2e8-e93cde282582'] = $pane;
    $display->panels['column_2___bottom'][1] = 'new-bb9c3f91-21fe-44d6-b2e8-e93cde282582';
    $pane = new stdClass();
    $pane->pid = 'new-54559c58-4829-4489-84bf-8b370cab02bd';
    $pane->panel = 'region_right';
    $pane->type = 'token';
    $pane->subtype = 'user:created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'sanitize' => 1,
      'context' => 'context_user_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '54559c58-4829-4489-84bf-8b370cab02bd';
    $display->content['new-54559c58-4829-4489-84bf-8b370cab02bd'] = $pane;
    $display->panels['region_right'][0] = 'new-54559c58-4829-4489-84bf-8b370cab02bd';
    $pane = new stdClass();
    $pane->pid = 'new-94c2cd59-4fe2-4090-969f-83e3298c7e72';
    $pane->panel = 'sidebar';
    $pane->type = 'views';
    $pane->subtype = 'articles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 1,
      'nodes_per_page' => '10',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'page',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '94c2cd59-4fe2-4090-969f-83e3298c7e72';
    $display->content['new-94c2cd59-4fe2-4090-969f-83e3298c7e72'] = $pane;
    $display->panels['sidebar'][0] = 'new-94c2cd59-4fe2-4090-969f-83e3298c7e72';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['panel'] = $page;

  return $pages;

}
