<?php
/**
 * @name blank
 * @param string $path = the module's internal path, as defined in our .module file
 * This is the default module class, this just helps us keep our items separated from Drupal
 * and keeps the module hooks in the .module file so that we know our work is as separated from Drupal's hooks
 * @todo - add any more path variables we need here.
 */
class menuImages {
  
  //Class variables here
  public $path;
  
  //Build any object references we need here - when we include this file, PHP will looks for the construct and give us this object automatically
  function __construct() {
    //Module Path
    $this->path = MENU_IMAGES_MODULE_PATH;
  }
  
  //When we are done with our object, or do not reference it anymore PHP will automatically try and kill it off from memory if we have this set
  function __destruct() {
    //Unset from memory
    unset( $this );
  }
  
  /**
   * @name _loadJS
   * Allows us to load the javascript files for the module anywhere in the module when we need it
   */
  public function _loadJS() {
    drupal_add_js( $this->path. '/js/jquery.module.js','module','header');
  }
  
  /**
   * @name _setMenuImageCache();
   * Add our own menu images cache data here
   * @param $newCache - the new array data we want to serialize into the cache_menu_image
   * @todo - we need to have this unset the array as well if $newCache is empty
   */
  public static function _setMenuImageCache($newCache) {
    //Get old cache.
    $oldCache = self::_getCache('all_menu_images');
    //Merge new data using our mlid as the key.
    $key = key($newCache);
    //Description field.
    $oldCache[$key]['description'] = $newCache[$key]['description'];
    $oldCache[$key]['file_title']  = $newCache[$key]['file_title'];
    $oldCache[$key]['file_alt']    = $newCache[$key]['file_alt'];
    //File Field, if we have an object or the value is DELETE.
    if ($newCache[$key]['file'] == 'DELETE') {
      unset($oldCache[$key]['file']);
    } else if (is_object($newCache[$key]['file'])) {
      $oldCache[$key]['file'] = $newCache[$key]['file'];
    }
    //Set new cache.
    self::_setCache('all_menu_images', $oldCache);
  }
  
  /**
   * @name _getCache
   * @param string $cid = the name of the cache table you are referencing
   * @param string $table = the cache table you're referencing
   * @return mixed $data->data = the unserialized entity you cached
   */
  public static function _getCache($cid, $table = 'cache_menu_images') { //unserializes the data you serialized, or returns false if no data is present
    $data = cache_get( $cid, $table );
    return ( is_object( $data ) ) ? unserialize( str_replace(array('O:16:"SimpleXMLElement":0:{}', 'O:16:"SimpleXMLElement":'), array('s:0:"";', 'O:8:"stdClass":'), $data->data ) ) : false;
  }
  
  /**
   * @name _setCache
   * @param string $cid = the name of the cache table you are referencing
   * @param mixed $data = the data your are serializing
   * @param mixed $expire = the expiration time for the cache, default to CACHE_PERMANENT
   * @param string $table = the cache table you're referencing
   * @return false or true, depending on if there is data to cache or not, and if there is a $cid attached
   */
  public static function _setCache($cid = NULL, $data = NULL, $expire = CACHE_PERMANENT, $table = 'cache_menu_images') {
    if ( $cid != null && $data != null ) { //serializes the data into the cached table of your choice
      cache_set( $cid, serialize( $data ), $table, $expire ); //everything is permanent in here
      return true;
    } else {
      return false;
    }
  }
  
}