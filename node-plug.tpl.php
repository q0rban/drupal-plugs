<?php

$type = $field_content_type[0]['value'];
$dest = $field_destination[0]['value'];
$options = array('absolute' => ($dest == 'field_external'));
$attributes = ${$dest}[0]['attributes'];
$dest_key = ($dest == 'field_external') ? 'url' : 'nid';
$url = url(${$dest}[0][$dest_key], $options);

?>

<div class="plug">
  <a href="<?php print $url; ?>" <?php print drupal_attributes($attributes); ?>><?php print ${$type}[0]['view']; ?></a>
</div>