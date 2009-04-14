<?php

/**
 * Implementation of hook_views_default_views().
 */
function plugs_views_default_views() {
  $views = array();

  $view = new view;
  $view->name = 'plugs';
  $view->description = 'Advertisements';
  $view->tag = 'plugs';
  $view->view_php = '';
  $view->base_table = 'node';
  $view->is_cacheable = FALSE;
  $view->api_version = 2;
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  $handler = $view->new_display('default', 'Advertisements', 'default');
  $handler->override_option('sorts', _plugs_view_sort());
  $handler->override_option('filters', array(
    'type' => array(
      'operator' => 'in',
      'value' => array(
        'plug' => 'plug',
      ),
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'type',
      'table' => 'node',
      'field' => 'type',
      'relationship' => 'none',
    ),
    'status' => array(
      'operator' => '=',
      'value' => 1,
      'group' => '0',
      'exposed' => FALSE,
      'expose' => array(
        'operator' => FALSE,
        'label' => '',
      ),
      'id' => 'status',
      'table' => 'node',
      'field' => 'status',
      'relationship' => 'none',
    ),
  ));
  $handler->override_option('access', array(
    'type' => 'none',
  ));
  $handler->override_option('title', 'Advertisements');
  $handler->override_option('items_per_page', variable_get('plugs_view_limit', 2));
  $handler->override_option('row_plugin', 'node');
  $handler->override_option('row_options', array(
    'teaser' => 0,
    'links' => 0,
    'comments' => 0,
  ));
  $handler = $view->new_display('block', 'Block', 'block_1');
  $handler->override_option('block_description', '');
  $handler->override_option('block_caching', -1);
  $views[$view->name] = $view;

  return $views;
}

/**
 * Helper function to create the array for the sorter.
 */
function _plugs_view_sort() {
  $sort = variable_get('plugs_view_sort', 'random');

  switch ($sort) {
    case 'random':
      return array(
        'random' => array(
          'order' => 'ASC',
          'id' => 'random',
          'table' => 'views',
          'field' => 'random',
          'relationship' => 'none',
        )
      );

    default:
      return array(
        'created' => array(
          'order' => $sort,
          'granularity' => 'second',
          'id' => 'created',
          'table' => 'node',
          'field' => 'created',
          'relationship' => 'none',
        )
      );
  }
}
