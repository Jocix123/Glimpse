/* libglimpse - The Glimpse Library
 * Copyright (C) 1995-2003 Peter Mattis and Spencer Kimball
 *
 * gimpfileops_pdb.c
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <https://www.gnu.org/licenses/>.
 */

/* NOTE: This file is auto-generated by pdbgen.pl */

#include "config.h"

#include <string.h>

#include "gimp.h"


/**
 * SECTION: gimpfileops
 * @title: gimpfileops
 * @short_description: Image file operations (load, save, etc.)
 *
 * Image file operations (load, save, etc.)
 **/


/**
 * gimp_file_load:
 * @run_mode: The run mode.
 * @filename: The name of the file to load.
 * @raw_filename: The name as entered by the user.
 *
 * Loads an image file by invoking the right load handler.
 *
 * This procedure invokes the correct file load handler using magic if
 * possible, and falling back on the file's extension and/or prefix if
 * not. The name of the file to load is typically a full pathname, and
 * the name entered is what the user actually typed before prepending a
 * directory path. The reason for this is that if the user types
 * https://www.gimp.org/foo.png he wants to fetch a URL, and the full
 * pathname will not look like a URL.
 *
 * Returns: The output image.
 **/
gint32
gimp_file_load (GimpRunMode  run_mode,
                const gchar *filename,
                const gchar *raw_filename)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint32 image_ID = -1;

  return_vals = gimp_run_procedure ("gimp-file-load",
                                    &nreturn_vals,
                                    GIMP_PDB_INT32, run_mode,
                                    GIMP_PDB_STRING, filename,
                                    GIMP_PDB_STRING, raw_filename,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    image_ID = return_vals[1].data.d_image;

  gimp_destroy_params (return_vals, nreturn_vals);

  return image_ID;
}

/**
 * gimp_file_load_layer:
 * @run_mode: The run mode.
 * @image_ID: Destination image.
 * @filename: The name of the file to load.
 *
 * Loads an image file as a layer for an existing image.
 *
 * This procedure behaves like the file-load procedure but opens the
 * specified image as a layer for an existing image. The returned layer
 * needs to be added to the existing image with
 * gimp_image_insert_layer().
 *
 * Returns: The layer created when loading the image file.
 *
 * Since: 2.4
 **/
gint32
gimp_file_load_layer (GimpRunMode  run_mode,
                      gint32       image_ID,
                      const gchar *filename)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint32 layer_ID = -1;

  return_vals = gimp_run_procedure ("gimp-file-load-layer",
                                    &nreturn_vals,
                                    GIMP_PDB_INT32, run_mode,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, filename,
                                    GIMP_PDB_END);

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    layer_ID = return_vals[1].data.d_layer;

  gimp_destroy_params (return_vals, nreturn_vals);

  return layer_ID;
}

/**
 * gimp_file_load_layers:
 * @run_mode: The run mode.
 * @image_ID: Destination image.
 * @filename: The name of the file to load.
 * @num_layers: The number of loaded layers.
 *
 * Loads an image file as layers for an existing image.
 *
 * This procedure behaves like the file-load procedure but opens the
 * specified image as layers for an existing image. The returned layers
 * needs to be added to the existing image with
 * gimp_image_insert_layer().
 *
 * Returns: The list of loaded layers.
 *
 * Since: 2.4
 **/
gint *
gimp_file_load_layers (GimpRunMode  run_mode,
                       gint32       image_ID,
                       const gchar *filename,
                       gint        *num_layers)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gint *layer_ids = NULL;

  return_vals = gimp_run_procedure ("gimp-file-load-layers",
                                    &nreturn_vals,
                                    GIMP_PDB_INT32, run_mode,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, filename,
                                    GIMP_PDB_END);

  *num_layers = 0;

  if (return_vals[0].data.d_status == GIMP_PDB_SUCCESS)
    {
      *num_layers = return_vals[1].data.d_int32;
      layer_ids = g_new (gint32, *num_layers);
      memcpy (layer_ids,
              return_vals[2].data.d_int32array,
              *num_layers * sizeof (gint32));
    }

  gimp_destroy_params (return_vals, nreturn_vals);

  return layer_ids;
}

/**
 * gimp_file_save:
 * @run_mode: The run mode.
 * @image_ID: Input image.
 * @drawable_ID: Drawable to save.
 * @filename: The name of the file to save the image in.
 * @raw_filename: The name as entered by the user.
 *
 * Saves a file by extension.
 *
 * This procedure invokes the correct file save handler according to
 * the file's extension and/or prefix. The name of the file to save is
 * typically a full pathname, and the name entered is what the user
 * actually typed before prepending a directory path. The reason for
 * this is that if the user types https://www.gimp.org/foo.png she
 * wants to fetch a URL, and the full pathname will not look like a
 * URL.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_file_save (GimpRunMode  run_mode,
                gint32       image_ID,
                gint32       drawable_ID,
                const gchar *filename,
                const gchar *raw_filename)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-file-save",
                                    &nreturn_vals,
                                    GIMP_PDB_INT32, run_mode,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_DRAWABLE, drawable_ID,
                                    GIMP_PDB_STRING, filename,
                                    GIMP_PDB_STRING, raw_filename,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_file_save_thumbnail:
 * @image_ID: The image.
 * @filename: The name of the file the thumbnail belongs to.
 *
 * Saves a thumbnail for the given image
 *
 * This procedure saves a thumbnail for the given image according to
 * the Free Desktop Thumbnail Managing Standard. The thumbnail is saved
 * so that it belongs to the file with the given filename. This means
 * you have to save the image under this name first, otherwise this
 * procedure will fail. This procedure may become useful if you want to
 * explicitly save a thumbnail with a file.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_file_save_thumbnail (gint32       image_ID,
                          const gchar *filename)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-file-save-thumbnail",
                                    &nreturn_vals,
                                    GIMP_PDB_IMAGE, image_ID,
                                    GIMP_PDB_STRING, filename,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_register_magic_load_handler:
 * @procedure_name: The name of the procedure to be used for loading.
 * @extensions: comma separated list of extensions this handler can load (i.e. \"jpg,jpeg\").
 * @prefixes: comma separated list of prefixes this handler can load (i.e. \"http:,ftp:\").
 * @magics: comma separated list of magic file information this handler can load (i.e. \"0,string,GIF\").
 *
 * Registers a file load handler procedure.
 *
 * Registers a procedural database procedure to be called to load files
 * of a particular file format using magic file information.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_register_magic_load_handler (const gchar *procedure_name,
                                  const gchar *extensions,
                                  const gchar *prefixes,
                                  const gchar *magics)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-register-magic-load-handler",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, procedure_name,
                                    GIMP_PDB_STRING, extensions,
                                    GIMP_PDB_STRING, prefixes,
                                    GIMP_PDB_STRING, magics,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_register_load_handler:
 * @procedure_name: The name of the procedure to be used for loading.
 * @extensions: comma separated list of extensions this handler can load (i.e. \"jpg,jpeg\").
 * @prefixes: comma separated list of prefixes this handler can load (i.e. \"http:,ftp:\").
 *
 * Registers a file load handler procedure.
 *
 * Registers a procedural database procedure to be called to load files
 * of a particular file format.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_register_load_handler (const gchar *procedure_name,
                            const gchar *extensions,
                            const gchar *prefixes)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-register-load-handler",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, procedure_name,
                                    GIMP_PDB_STRING, extensions,
                                    GIMP_PDB_STRING, prefixes,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_register_save_handler:
 * @procedure_name: The name of the procedure to be used for saving.
 * @extensions: comma separated list of extensions this handler can save (i.e. \"jpg,jpeg\").
 * @prefixes: comma separated list of prefixes this handler can save (i.e. \"http:,ftp:\").
 *
 * Registers a file save handler procedure.
 *
 * Registers a procedural database procedure to be called to save files
 * in a particular file format.
 *
 * Returns: TRUE on success.
 **/
gboolean
gimp_register_save_handler (const gchar *procedure_name,
                            const gchar *extensions,
                            const gchar *prefixes)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-register-save-handler",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, procedure_name,
                                    GIMP_PDB_STRING, extensions,
                                    GIMP_PDB_STRING, prefixes,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_register_file_handler_priority:
 * @procedure_name: The name of the procedure to set the priority of.
 * @priority: The procedure priority.
 *
 * Sets the priority of a file handler procedure.
 *
 * Sets the priority of a file handler procedure. When more than one
 * procedure matches a given file, the procedure with the lowest
 * priority is used; if more than one procedure has the lowest
 * priority, it is unspecified which one of them is used. The default
 * priority for file handler procedures is 0.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.10.6
 **/
gboolean
gimp_register_file_handler_priority (const gchar *procedure_name,
                                     gint         priority)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-register-file-handler-priority",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, procedure_name,
                                    GIMP_PDB_INT32, priority,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_register_file_handler_mime:
 * @procedure_name: The name of the procedure to associate a MIME type with.
 * @mime_types: A comma-separated list of MIME types, such as \"image/jpeg\".
 *
 * Associates MIME types with a file handler procedure.
 *
 * Registers MIME types for a file handler procedure. This allows GIMP
 * to determine the MIME type of the file opened or saved using this
 * procedure. It is recommended that only one MIME type is registered
 * per file procedure; when registering more than one MIME type, GIMP
 * will associate the first one with files opened or saved with this
 * procedure.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_register_file_handler_mime (const gchar *procedure_name,
                                 const gchar *mime_types)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-register-file-handler-mime",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, procedure_name,
                                    GIMP_PDB_STRING, mime_types,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_register_file_handler_uri:
 * @procedure_name: The name of the procedure to enable URIs for.
 *
 * Registers a file handler procedure as capable of handling URIs.
 *
 * Registers a file handler procedure as capable of handling URIs. This
 * allows GIMP to call the procedure directly for all kinds of URIs,
 * and the 'filename' traditionally passed to file procedures turns
 * into an URI.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.10
 **/
gboolean
gimp_register_file_handler_uri (const gchar *procedure_name)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-register-file-handler-uri",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, procedure_name,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_register_file_handler_raw:
 * @procedure_name: The name of the procedure to enable raw handling for.
 *
 * Registers a file handler procedure as capable of handling raw camera
 * files.
 *
 * Registers a file handler procedure as capable of handling raw
 * digital camera files. Use this procedure only to register raw load
 * handlers, calling it on a save handler will generate an error.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.10
 **/
gboolean
gimp_register_file_handler_raw (const gchar *procedure_name)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-register-file-handler-raw",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, procedure_name,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}

/**
 * gimp_register_thumbnail_loader:
 * @load_proc: The name of the procedure the thumbnail loader with.
 * @thumb_proc: The name of the thumbnail load procedure.
 *
 * Associates a thumbnail loader with a file load procedure.
 *
 * Some file formats allow for embedded thumbnails, other file formats
 * contain a scalable image or provide the image data in different
 * resolutions. A file plug-in for such a format may register a special
 * procedure that allows GIMP to load a thumbnail preview of the image.
 * This procedure is then associated with the standard load procedure
 * using this function.
 *
 * Returns: TRUE on success.
 *
 * Since: 2.2
 **/
gboolean
gimp_register_thumbnail_loader (const gchar *load_proc,
                                const gchar *thumb_proc)
{
  GimpParam *return_vals;
  gint nreturn_vals;
  gboolean success = TRUE;

  return_vals = gimp_run_procedure ("gimp-register-thumbnail-loader",
                                    &nreturn_vals,
                                    GIMP_PDB_STRING, load_proc,
                                    GIMP_PDB_STRING, thumb_proc,
                                    GIMP_PDB_END);

  success = return_vals[0].data.d_status == GIMP_PDB_SUCCESS;

  gimp_destroy_params (return_vals, nreturn_vals);

  return success;
}
