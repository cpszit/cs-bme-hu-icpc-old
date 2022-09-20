<?php
/*
 * Gallery - a web based photo album viewer and editor
 * Copyright (C) 2000-2002 Bharat Mediratta
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */
?>
<?php
/* 
 * Protect against very old versions of 4.0 (like 4.0RC1) which  
 * don't implicitly create a new stdClass() when you use a variable 
 * like a class. 
 */ 
if (!$gallery) { 
        $gallery = new stdClass(); 
}
if (!$gallery->app) { 
        $gallery->app = new stdClass(); 
}

/* Version  */
$gallery->app->config_version = 31;

/* Features */
$gallery->app->feature["zip"] = 1;
$gallery->app->feature["rewrite"] = 0; // (missing <i>GALLERY_REWRITE_OK</i> -- it's optional)
$gallery->app->feature["mirror"] = 0; // (missing <i>mirrorSites</i> -- it's optional)

/* Constants */
$gallery->app->galleryTitle = "ACM";
$gallery->app->pnmDir = "/usr/bin";
$gallery->app->ImPath = "/usr/bin";
$gallery->app->graphics = "NetPBM";
$gallery->app->highlight_size = "200";
$gallery->app->zipinfo = "/usr/bin/zipinfo";
$gallery->app->unzip = "/usr/bin/unzip";
$gallery->app->use_exif = "/usr/bin/jhead";
$gallery->app->movieThumbnail = "/home/dmarx/public_html/acm/gallery/images/movie.thumb.jpg";
$gallery->app->albumDir = "/home/dmarx/public_html/acm/gallery/albums";
$gallery->app->tmpDir = "/tmp";
$gallery->app->photoAlbumURL = "http://www.cs.bme.hu/acm/gallery";
$gallery->app->albumDirURL = "http://www.cs.bme.hu/acm/gallery/albums";
// optional <i>mirrorSites</i> missing
$gallery->app->showAlbumTree = "no";
$gallery->app->cacheExif = "no";
$gallery->app->jpegImageQuality = "95";
$gallery->app->timeLimit = "30";
$gallery->app->debug = "no";
$gallery->app->use_flock = "yes";
$gallery->app->expectedExecStatus = "0";
$gallery->app->sessionVar = "gallery_session";
$gallery->app->userDir = "/home/dmarx/public_html/acm/gallery/albums/.users";
$gallery->app->pnmtojpeg = "pnmtojpeg";

/* Defaults */
$gallery->app->default["bordercolor"] = "black";
$gallery->app->default["border"] = "1";
$gallery->app->default["font"] = "arial";
$gallery->app->default["cols"] = "3";
$gallery->app->default["rows"] = "3";
$gallery->app->default["thumb_size"] = "150";
$gallery->app->default["resize_size"] = "640";
$gallery->app->default["fit_to_window"] = "no";
$gallery->app->default["use_fullOnly"] = "no";
$gallery->app->default["print_photos"] = "none";
$gallery->app->default["returnto"] = "yes";
$gallery->app->default["showOwners"] = "no";
$gallery->app->default["albumsPerPage"] = "5";
$gallery->app->default["showSearchEngine"] = "yes";
$gallery->app->default["useOriginalFileNames"] = "yes";
$gallery->app->default["display_clicks"] = "yes";
$gallery->app->default["public_comments"] = "yes";
?>
