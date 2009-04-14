$(function() {
  // Hide everything first.
  $('#edit-field-internal-nid-nid-wrapper,#edit-field-external-0-url-wrapper,#edit-field-html-0-value-wrapper,fieldset.group-content > fieldset.collapsible,#edit-field-plug-image-0-ahah-wrapper').hide();

  // Here's our 'Destination' group
  $('input#edit-field-destination-value-field-internal, input#edit-field-destination-value-field-external').change(function() {
    var val = $(this).val();
    if (val == 'field_internal') {
      $('select#edit-field-internal-nid-nid').val('');
      $('#edit-field-external-0-url-wrapper').hide('fast');
      $('#edit-field-internal-nid-nid-wrapper').show('slow');
    }
    else {
      $('input#edit-field-external-0-url').val('');
      $('#edit-field-internal-nid-nid-wrapper').hide('fast');
      $('#edit-field-external-0-url-wrapper').show('slow');
    }
  });

  // Here's our 'Content Type' group
  $('input#edit-field-content-type-value-field-plug-image, input#edit-field-content-type-value-field-html').change(function() {
    var val = $(this).val();
    if (val == 'field_html') {

      // Remove the data in the field if any, and remove the image if it's been uploaded.
      $('input#edit-field-plug-image-0-upload').val('');

      //@todo: find a way to remove the image.
      //$('#edit-field-plug-image-0-remove-btn').click();

      // Show/hide the divs.
      $('#edit-field-plug-image-0-ahah-wrapper').hide('fast');
      $('#edit-field-html-0-value-wrapper, fieldset.group-content > fieldset.collapsible').show('slow');
    }
    else {
      // Remove the data in the field if any
      // @todo: find a way to remove the html contents when wysiwyg is used.
      $('textarea#edit-field-html-0-value').val('');

      // Show/hide the divs.
      $('#edit-field-html-0-value-wrapper, fieldset.group-content > fieldset.collapsible').hide('fast');
      $('#edit-field-plug-image-0-ahah-wrapper').show('slow');
    }
  });
  
    // Mimic a change to show what is already selected on page load.
  $('input[id*=edit-field-content-type-value-field]:checked, input[id*=edit-field-destination-value-field]:checked', 'fieldset.group-destination, fieldset.group-content').change();
});