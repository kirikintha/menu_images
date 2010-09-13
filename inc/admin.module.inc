<?php
/**
 * @name admin.module.inc
 * This is our module's admin functions
 */

/**
 * Main settings form
 */
function _menu_images_main_settings() {
  //Manually Update All Weather
  $form['main'] = array(
    '#type'        => 'fieldset',
    '#title'       => t('Menu Images Main Settings'),
    '#description' => t('This is where you configure the menu images settings.'),
		'#collapsible' 	=> FALSE,
		'#collapsed' 		=> FALSE,
		'#weight'				=> -50,
    '#group'       => 'main',
  );
  //Image Dimensions, per file api.
  $form['main']['menu_image_picture_dimensions'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Image Dimensions'),
    '#description'   => t('Enter in the image dimensions that are acceptable for this module.'),
    '#default_value' => variable_get('menu_image_picture_dimensions', '85x85'),
    '#required'      => TRUE,
    '#group'         => 'main',
  );
  //Max image size, per file api.
  $form['main']['menu_image_picture_file_size'] = array(
    '#type'          => 'textfield',
    '#title'         => t('Image File Size'),
    '#description'   => t('Enter in the maximum image files size in Megabytes that is acceptable for this module.'),
    '#default_value' => variable_get('menu_image_picture_file_size', '30'),
    '#required'      => TRUE,
    '#group'         => 'main',
  );
  //Enable vertical tabs if installed.
  $form['#pre_render'][] = 'vertical_tabs_form_pre_render';
  return system_settings_form($form);
}