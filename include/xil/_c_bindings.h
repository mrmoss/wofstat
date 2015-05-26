/*------------------------------------------------------------------------
* 
*   File:	_c_bindings.h
*   Project:	XIL
*   Revision:	1.47
*   Last Mod:	17:21:08, 06/10/98
* 
*   Description:
* 		
* 	C-side of function declarations of C-callable bindings for XIL.
* 	
*------------------------------------------------------------------------*/

#ifndef _XIL_C_BINDINGS_H
#define _XIL_C_BINDINGS_H

#ifndef XIL_API_MAJOR_VERSION
#define XIL_API_MAJOR_VERSION    1
#endif

#ifndef XIL_API_MINOR_VERSION
#define XIL_API_MINOR_VERSION    4
#endif

XilSystemState 
xil_open();

void 
xil_close(XilSystemState system_state);

XilImage 
xil_create(XilSystemState system_state,
           unsigned int   width,
           unsigned int   height,
           unsigned int   nbands,
           XilDataType    datatype);

XilImage
xil_create_from_type(XilSystemState system_state,
                     XilImageType   imagetype);

/*
 *  Temporary Images
 */
XilImage 
xil_create_temporary(XilSystemState system_state,
                     unsigned int   width,
                     unsigned int   height,
                     unsigned int   nbands,
                     XilDataType    datatype);

XilImage
xil_create_temporary_from_type(XilSystemState system_state,
                               XilImageType   imagetype);

XilImage
xil_create_child(XilImage src, 
                 unsigned int xstart, unsigned int ystart, 
                 unsigned int width, unsigned int height, 
                 unsigned int startband, unsigned int numbands);

XilImage
xil_create_copy(XilImage src, 
                unsigned int xstart, unsigned int ystart, 
                unsigned int width, unsigned int height, 
                unsigned int startband, unsigned int numbands);

XilImage
xil_create_from_device(XilSystemState system_state,
                       char*          devicename,
                       XilDevice      attribs);

XilImage
xil_create_from_window(XilSystemState system_state,
                       Display*       display,
                       Window         window);

XilImage
xil_create_double_buffered_window(XilSystemState system_state,
                                  Display*       display,
                                  Window         window);


XilImage
xil_create_from_special_window(XilSystemState system_state,
                               Display*       display,
                               Window         window,
                               XilWindowCaps  wincaps);

void 
xil_copy(XilImage src, XilImage dst);

void 
xil_absolute(XilImage src1, XilImage dst);

void 
xil_min(XilImage src1, XilImage src2, XilImage dst);

void 
xil_max(XilImage src1, XilImage src2, XilImage dst);

void 
xil_add(XilImage src1, XilImage src2, XilImage dst);

void
xil_subtract(XilImage src1, XilImage src2, XilImage dst);

void 
xil_multiply(XilImage src1, XilImage src2, XilImage dst);

void 
xil_divide(XilImage src1, XilImage src2, XilImage dst);

void 
xil_and(XilImage src1, XilImage src2, XilImage dst);

void 
xil_or(XilImage src1, XilImage src2, XilImage dst);

void 
xil_xor(XilImage src1, XilImage src2, XilImage dst);

void 
xil_add_const(XilImage src, float* vector, XilImage dst);

void 
xil_subtract_const(XilImage src, float* vector, XilImage dst);

void 
xil_subtract_from_const(float* vector, XilImage src, XilImage dst);

void 
xil_multiply_const(XilImage src, float* vector, XilImage dst);

void 
xil_divide_by_const(XilImage src, float* vector, XilImage dst);

void 
xil_divide_into_const(float* vector, XilImage src, XilImage dst);

void 
xil_and_const(XilImage src, unsigned int* vector, XilImage dst);

void 
xil_or_const(XilImage src, unsigned int* vector, XilImage dst);

void 
xil_xor_const(XilImage src, unsigned int* vector, XilImage dst);

void 
xil_nearest_color(XilImage src, XilImage dst, XilLookup cmap);

void 
xil_extrema(XilImage src, float* max, float* min);

XilLookup
xil_squeeze_range(XilImage src);

void
xil_black_generation(XilImage src, XilImage dst, float black, 
		      float undercolor);

void 
xil_not(XilImage src, XilImage dst);

void 
xil_lookup(XilImage src, XilImage dst, XilLookup lookup);

XilLookup	
xil_lookup_create(XilSystemState system_state,
		  XilDataType input_datatype,
		  XilDataType output_datatype,
		  unsigned int output_nbands, 
		  unsigned int num_entries,
		  short first_entry_offset,
                  void* data);

XilLookup	
xil_lookup_create_combined(XilSystemState system_state,
			   XilLookup lookup_list[],
			   unsigned int num_lookups);

XilLookup	
xil_colorcube_create(XilSystemState system_state,
		     XilDataType input_type,
		     XilDataType output_type,
		     unsigned int nbands,
		     short offset,
		     int multipliers[],
		     unsigned int dimensions[]);

void	
xil_lookup_destroy(XilLookup lookup);

XilLookup	
xil_lookup_get_band_lookup(XilLookup lookup, 
			   unsigned int band_num);

XilDataType	
xil_lookup_get_input_datatype(XilLookup lookup);

XilDataType	
xil_lookup_get_output_datatype(XilLookup lookup);

unsigned int	
xil_lookup_get_output_nbands(XilLookup lookup);

unsigned int	
xil_lookup_get_input_nbands(XilLookup lookup);

unsigned int	
xil_lookup_get_num_entries(XilLookup lookup);

XilVersionNumber 
xil_lookup_get_version(XilLookup lookup);

short		
xil_lookup_get_offset(XilLookup lookup);

void		
xil_lookup_set_offset(XilLookup lookup, short offset);

Xil_boolean	
xil_lookup_get_colorcube(XilLookup lookup);

Xil_boolean	
xil_lookup_get_colorcube_info(XilLookup lookup,
			      int* multipliers, unsigned int* counts,
			      short* origin);

void	
xil_lookup_get_values(XilLookup lookup, 
		      short start, unsigned int num_values, 
		      void* data);

void	
xil_lookup_set_values(XilLookup lookup, 
		      short start, unsigned int num_values, 
		      void* data);

XilLookup
xil_lookup_create_copy(XilLookup lookup);

XilHistogram
xil_histogram_create(XilSystemState system_state,
		     unsigned int nbands,
		     unsigned int *nbins,
		     float *low_value,
		     float *high_value);

XilHistogram
xil_histogram_create_copy(XilHistogram);

void
xil_histogram_get_values(XilHistogram histogram,
			 unsigned int *data);

void
xil_histogram_get_limits(XilHistogram histogram,
			 float *low_value, float *high_value);

void            
xil_histogram_get_info(XilHistogram histogram,
		       unsigned int *nbands, unsigned int *nbins,
		       float *low_value, float *high_value);

void		
xil_histogram_get_nbins(XilHistogram histogram,
			unsigned int *nbins);

unsigned int	
xil_histogram_get_nbands(XilHistogram histogram);

void		
xil_histogram_destroy(XilHistogram histogram);

void 		
xil_histogram(XilImage src, XilHistogram histogram,
	      unsigned int skip_x, unsigned int skip_y);


void
xil_tablewarp(XilImage src, XilImage dst, 
                   char* interpolation, XilImage warp_table);

void
xil_tablewarp_horizontal(XilImage src, XilImage dst, 
                              char* interpolation, XilImage warp_table);

void
xil_tablewarp_vertical(XilImage src, XilImage dst, 
                            char* interpolation, XilImage warp_table);

void
xil_edge_detection(XilImage src, XilImage dst, XilEdgeDetection method);

void
xil_scale(XilImage src, XilImage dst, char* interpolation, float xscale, 
		float yscale);

void
xil_subsample_adaptive(XilImage src, XilImage dst, float xscale, float yscale);

void
xil_subsample_binary_to_gray(XilImage src, XilImage dst, float xscale, 
				  float yscale);

void
xil_rotate(XilImage src, XilImage dst, char* interpolation, float angle);

void
xil_translate(XilImage src, XilImage dst, char* interpolation,
			float xoffset, float yoffset);

void
xil_affine(XilImage src, XilImage dst, char* interpolation, float* matrix);

void
xil_transpose(XilImage src, XilImage dst, XilFlipType fliptype);

void
xil_compress(XilImage src, XilCis cis);

int
xil_cis_has_data(XilCis cis);

Xil_boolean
xil_cis_has_frame(XilCis cis);

void*
xil_cis_get_bits_ptr(XilCis cis, int* nbytes, int* nframes);

void
xil_cis_flush(XilCis cis);

void
xil_cis_sync(XilCis cis);

void
xil_cis_reset(XilCis cis);

void
xil_cis_put_bits(XilCis cis,
                 int    nbytes,
                 int    nframes,
                 void*  data);

void
xil_cis_put_bits_ptr(XilCis                     cis,
                     int                        nbytes,
                     int                        nframes,
                     void*                      data,
                     XIL_FUNCPTR_DONE_WITH_DATA done_with_data);

void
xil_decompress(XilCis   cis,
               XilImage dst);

void
xil_cis_seek(XilCis cis,
             int    frame_number,
             int    relative_to);

int
xil_cis_number_of_frames(XilCis cis);

char*
xil_cis_get_compressor(XilCis cis);

char*
xil_cis_get_compression_type(XilCis cis);

int
xil_cis_get_random_access(XilCis cis);

int
xil_cis_get_start_frame(XilCis cis);

int
xil_cis_get_read_frame(XilCis cis);

int
xil_cis_get_write_frame(XilCis cis);

Xil_boolean
xil_cis_get_read_invalid(XilCis cis);

Xil_boolean
xil_cis_get_write_invalid(XilCis cis);

Xil_boolean
xil_cis_get_autorecover(XilCis cis);

void
xil_cis_set_autorecover(XilCis cis, Xil_boolean on_off);

void
xil_cis_attempt_recovery(XilCis cis, unsigned int nframes, unsigned int nbytes);

XilImageType
xil_cis_get_output_type(XilCis cis);

XilImageType
xil_cis_get_input_type(XilCis cis);

int
xil_cis_get_keep_frames(XilCis cis);

void
xil_cis_set_keep_frames(XilCis cis, int keep);

int
xil_cis_get_max_frames(XilCis cis);

void
xil_cis_set_max_frames(XilCis cis, int max);

void
xil_color_convert(XilImage src, XilImage dst);

void
xil_ordered_dither(XilImage src, XilImage dst, XilLookup cmap, 
			XilDitherMask mask);

void
xil_error_diffusion(XilImage src, XilImage dst, XilLookup cmap, 
			 XilKernel distribution);

XilLookup
xil_lookup_convert(XilLookup src, XilLookup dst);

XilLookup
xil_choose_colormap(XilImage src, unsigned int size);

void
xil_paint(XilImage src, XilImage dst, float* color, XilKernel brush, 
		unsigned int count, float* coord_list);

void
xil_blend(XilImage src1, XilImage src2, XilImage dst, XilImage alpha);

void
xil_cast(XilImage src, XilImage dst);

void
xil_fill(XilImage src, XilImage dst, float xseed, float yseed,
	      float* boundary, float* fill_color);

void
xil_soft_fill(XilImage src, XilImage dst, float xseed, float yseed,
	      float* fgcolor, unsigned int num_bgcolor, float* bgcolor,
	      float* fill_color);

void
xil_convolve(XilImage src, XilImage dst, XilKernel kernel,
		  XilEdgeCondition edge_condition);

void
xil_band_combine(XilImage src, XilImage dst, XilKernel kernel);

void
xil_erode(XilImage src, XilImage dst, XilSel sel);

void
xil_dilate(XilImage src, XilImage dst, XilSel sel);

void
xil_copy_pattern(XilImage src, XilImage dst);

void
xil_copy_with_planemask(XilImage src, XilImage dst,
		             unsigned int* vector);

void
xil_threshold(XilImage src, XilImage dst, float *lowvalue, 
		   float *highvalue, float *mapvalue);


void
xil_set_value(XilImage dst, float* values);

void
xil_rescale(XilImage src, XilImage dst, float* scale, float* offset);

void
xil_set_active_buffer(XilImage    image,
                      XilBufferId id);

XilBufferId
xil_get_active_buffer(XilImage image);

void
xil_swap_buffers(XilImage image);

void
xil_destroy(XilImage image);

int 
xil_export(XilImage image);

int 
xil_get_exported(XilImage image);

void
xil_import(XilImage image, Xil_boolean change_flag);

void
xil_sync(XilImage image);

void
xil_toss(XilImage image);

void
xil_get_tilesize(XilImage      image,
                 unsigned int* tile_xsize,
                 unsigned int* tile_ysize);

void
xil_get_tilesize(XilImage      image,
                 unsigned int* tile_xsize,
                 unsigned int* tile_ysize);
void
xil_set_tilesize(XilImage     image,
                 unsigned int tile_xsize,
                 unsigned int tile_ysize);

Xil_boolean
xil_get_tile_storage(XilImage     image,
                     unsigned int x,
                     unsigned int y,
                     XilStorage   storage);

Xil_boolean
xil_set_tile_storage(XilImage   image,
                     XilStorage storage);

XilStorage
xil_get_storage_with_copy(XilImage   image);

int
xil_set_storage_with_copy(XilImage   image,
                          XilStorage storage);

Xil_boolean
xil_state_get_synchronize(XilSystemState system_state);

void
xil_state_set_synchronize(XilSystemState system_state,
                          Xil_boolean    onoff);

int
xil_state_get_default_tilesize(XilSystemState  system_state,
                               unsigned int*   txsize_ptr,
                               unsigned int*   tysize_ptr);

int
xil_state_set_default_tilesize(XilSystemState  system_state,
                               unsigned int    txsize,
                               unsigned int    tysize);

XilTilingMode
xil_state_get_default_tiling_mode(XilSystemState system_state);
 
int
xil_state_set_default_tiling_mode(XilSystemState system_state,
                                  XilTilingMode   mode);

void
xil_state_set_show_action( XilSystemState system_state, int env_on_off );

int
xil_state_get_show_action( XilSystemState system_state );

void
xil_state_set_provide_warnings(XilSystemState system_state,
                               int            flag_on_off);

int
xil_state_get_provide_warnings(XilSystemState system_state);

void
xil_state_set_interpolation_tables(XilSystemState system_state, 
                                   XilInterpolationTable horiz_kernel, 
                                   XilInterpolationTable vertical_kernel);

void
xil_state_get_interpolation_tables(XilSystemState system_state, 
                                   XilInterpolationTable* horiz_kernel,
                                   XilInterpolationTable* vertical_kernel);

Xil_boolean
xil_get_synchronize(XilImage image);

void
xil_set_synchronize(XilImage image, Xil_boolean onoff);

unsigned int
xil_get_width(XilImage image);

unsigned int
xil_get_height(XilImage image);

unsigned int
xil_get_nbands(XilImage image);

void
xil_get_size(XilImage      image,
             unsigned int* width,
             unsigned int* height);

XilDataType
xil_get_datatype(XilImage image);

void
xil_get_info(XilImage      image,
             unsigned int* width,
             unsigned int* height,
             unsigned int* nbands,
             XilDataType*  datatype);

void
xil_get_child_offsets(XilImage image,unsigned int* offsetX, 
     unsigned int* offsetY, unsigned int* offsetBand);

unsigned int
xil_imagetype_get_width(XilImageType imagetype);

unsigned int
xil_imagetype_get_height(XilImageType imagetype);

unsigned int
xil_imagetype_get_nbands(XilImageType imagetype);

void
xil_imagetype_get_size(XilImageType imagetype, unsigned int* width,
	unsigned int* height);

XilDataType
xil_imagetype_get_datatype(XilImageType imagetype);

void
xil_imagetype_get_info(XilImageType imagetype, unsigned int* width,
	unsigned int* height, unsigned int* nbands,
	XilDataType* datatype);

XilImage
xil_get_parent(XilImage image);

XilRoi	
xil_get_roi(XilImage image);

void	
xil_set_roi(XilImage image, XilRoi roi);

float
xil_get_origin_x(XilImage image);

float
xil_get_origin_y(XilImage image);

void
xil_get_origin(XilImage image, float* x, float* y);

void
xil_set_colorspace(XilImage image, XilColorspace cspace);

void
xil_set_origin(XilImage image, float x, float y);

void
xil_set_pixel(XilImage image, unsigned int x, unsigned int y, float* values);

void
xil_get_pixel(XilImage image, unsigned int x, unsigned int y, float* values);

XilImageType 
xil_get_imagetype(XilImage image);

Xil_boolean
xil_get_memory_storage(XilImage src, XilMemoryStorage* storage);

Xil_boolean
xil_get_readable(XilImage src);

Xil_boolean
xil_get_writeable(XilImage src);

Xil_boolean
xil_get_writable(XilImage src);

void
xil_set_memory_storage(XilImage src, XilMemoryStorage* storage);

int
xil_get_attribute(XilImage image, char* attribute, void** value);

int
xil_set_attribute(XilImage image, char* attribute, void* value);

int
xil_get_device_attribute(XilImage image, char* attribute, void** value);

int
xil_set_device_attribute(XilImage image, char* attribute, void* value);

void
xil_set_data_supply_routine(XilImage image,
                            XilDataSupplyFuncPtr supply_ptr,
                            void* user_args);         

XilCis
xil_cis_create(XilSystemState system_state, 
		       char* compressorname);

void
xil_cis_destroy(XilCis cis);

int
xil_cis_get_attribute(XilCis cis, char* attribute, void** value);

int
xil_cis_set_attribute(XilCis cis, char* attribute, void*  value);

XilRoi
xil_roi_create(XilSystemState state);

void
xil_roi_destroy(XilRoi roi);

void
xil_roi_add_rect(XilRoi roi, long x, long y,
	long width, long height);

void
xil_roi_subtract_rect(XilRoi roi, long x, long y,
	long width, long height);

XilRoi
xil_roi_unite(XilRoi roi, XilRoi more_regions);

XilRoi
xil_roi_intersect(XilRoi roi1, XilRoi roi2);

XilRoi
xil_roi_translate(XilRoi roi, int x, int y);

XilRoi
xil_roi_scale(XilRoi roi, float xscale, float yscale, 
		float xorigin, float yorigin);

XilRoi
xil_roi_transpose(XilRoi roi, XilFlipType fliptype, float xorigin, 
		float yorigin);

XilRoi
xil_roi_create_copy(XilRoi roi);

#if defined(_XIL_HAS_X11WINDOWS) || defined(_WINDOWS)
void
xil_roi_add_region(XilRoi roi, Region region);

Region
xil_roi_get_as_region(XilRoi roi);
#endif

void
xil_roi_add_image(XilRoi roi, XilImage image);


XilImage
xil_roi_get_as_image(XilRoi roi);


XilKernel
xil_kernel_create(XilSystemState system_state,
                  unsigned int   width,
                  unsigned int   height, 
                  unsigned int   keyx,
                  unsigned int   keyy,
                  float*         data);

XilKernel
xil_kernel_create_separable(XilSystemState system_state,
                            unsigned int   width,
                            unsigned int   height,
                            unsigned int   keyx,
                            unsigned int   keyy,
                            float*         x_data,
                            float*         y_data);

XilKernel
xil_kernel_create_copy(XilKernel kernel);

void
xil_kernel_destroy(XilKernel kernel);

unsigned int
xil_kernel_get_width(XilKernel kernel);

unsigned int
xil_kernel_get_height(XilKernel kernel);

unsigned int
xil_kernel_get_key_x(XilKernel kernel);

unsigned int
xil_kernel_get_key_y(XilKernel kernel);

void
xil_kernel_get_values(XilKernel kernel, float* data);

XilDitherMask
xil_dithermask_create(XilSystemState system_state,
	unsigned int width, unsigned int height, 
	unsigned int nbands, float* data);

void
xil_dithermask_destroy(XilDitherMask mask);

unsigned int
xil_dithermask_get_width(XilDitherMask mask);

unsigned int
xil_dithermask_get_height(XilDitherMask mask);

unsigned int
xil_dithermask_get_nbands(XilDitherMask mask);

XilDitherMask
xil_dithermask_create_copy(XilDitherMask mask);

void
xil_dithermask_get_values(XilDitherMask mask, float* data);


XilSel
xil_sel_create(XilSystemState system_state,
	unsigned int width, unsigned int height, unsigned int keyx, unsigned int keyy,
	unsigned int* data);

void
xil_sel_destroy(XilSel sel);

unsigned int
xil_sel_get_height(XilSel sel);

unsigned int
xil_sel_get_width(XilSel sel);

unsigned int
xil_sel_get_key_x(XilSel sel);

unsigned int
xil_sel_get_key_y(XilSel sel);

XilSel
xil_sel_create_copy(XilSel sel);

void
xil_sel_get_values(XilSel sel, unsigned int *data);


XilDevice   
xil_device_create(XilSystemState system_state,
			char* device_name);

void	
xil_device_destroy(XilDevice attribObject);

void	
xil_device_set_value(XilDevice attribObject,
                     char* attribute_name,
                     void* attribute_value);

void	
xil_device_set_attribute(XilDevice attribObject,
                         char* attribute_name,
                         void* attribute_value);

XilInterpolationTable   
xil_interpolation_table_create(XilSystemState system_state,
                               unsigned int kernel_size,
                               unsigned int subsamples,
                               float* data);

XilInterpolationTable
xil_interpolation_table_create_copy(XilInterpolationTable);

void	
xil_interpolation_table_destroy(XilInterpolationTable table);

unsigned int   
xil_interpolation_table_get_subsamples(XilInterpolationTable table);

unsigned int   
xil_interpolation_table_get_kernel_size(XilInterpolationTable table);

float*         
xil_interpolation_table_get_data(XilInterpolationTable table);

void
xil_interpolation_table_get_values(XilInterpolationTable table,
                                   float*                data);

int
xil_install_error_handler(XilSystemState system_state,XilErrorFunc func);

void
xil_remove_error_handler(XilSystemState system_state,
    				  XilErrorFunc func);

Xil_boolean    
xil_call_next_error_handler(XilError error);

Xil_boolean
xil_default_error_handler(XilError error);

char*
xil_error_get_string(XilError error);

char*  
xil_error_get_id(XilError error);

XilErrorCategory
xil_error_get_category(XilError error);

char*  
xil_error_get_category_string(XilError error);

char*  
xil_error_get_location(XilError error);

Xil_boolean
xil_error_get_primary(XilError error);

Xil_boolean
xil_error_is_warning(XilError error);

XilObject  
xil_error_get_object(XilError error);

void
xil_object_get_error_string(XilObject object,char* string,int string_size);

XilObjectType
xil_object_get_type(XilObject object);

/*
 *  Get assorted XilObjects by name.
 */
XilImage
xil_get_by_name(XilSystemState, char*);

XilImageType
xil_imagetype_get_by_name(XilSystemState, char*);

XilLookup
xil_lookup_get_by_name(XilSystemState, char*);

XilCis
xil_cis_get_by_name(XilSystemState, char*);

XilDitherMask
xil_dithermask_get_by_name(XilSystemState, char*);

XilKernel
xil_kernel_get_by_name(XilSystemState, char*);

XilSel
xil_sel_get_by_name(XilSystemState, char*);

XilRoi
xil_roi_get_by_name(XilSystemState, char*);

XilHistogram
xil_histogram_get_by_name(XilSystemState, char*);

XilStorage
xil_storage_get_by_name(XilSystemState, char*);

XilColorspace
xil_colorspace_get_by_name(XilSystemState, char*);

XilColorspaceList
xil_colorspacelist_get_by_name(XilSystemState, char*);

/*
 *  Get the name associated with the given XilObject.
 */
char*
xil_get_name(XilImage);

char*
xil_imagetype_get_name(XilImageType);

char*
xil_lookup_get_name(XilLookup);

char*
xil_cis_get_name(XilCis);

char*
xil_dithermask_get_name(XilDitherMask);

char*
xil_kernel_get_name(XilKernel);

char*
xil_sel_get_name(XilSel);

char*
xil_roi_get_name(XilRoi);

char*
xil_histogram_get_name(XilHistogram);

char*
xil_storage_get_name(XilStorage);

char*
xil_colorspace_get_name(XilColorspace);

char*
xil_colorspacelist_get_name(XilColorspaceList);

/*
 *  Set the name for the given XilObject.
 */
void
xil_set_name(XilImage, char*);

void
xil_imagetype_set_name(XilImageType, char*);

void
xil_lookup_set_name(XilLookup, char*);

void
xil_cis_set_name(XilCis, char*);

void
xil_dithermask_set_name(XilDitherMask, char*);

void
xil_kernel_set_name(XilKernel, char*);

void
xil_sel_set_name(XilSel, char*);

void
xil_roi_set_name(XilRoi, char*);

void
xil_histogram_set_name(XilHistogram, char*);

void
xil_storage_set_name(XilStorage, char*);

void
xil_set_storage_movement(XilImage image,
                         XilStorageMovement move_flag);

XilStorageMovement
xil_get_storage_movement(XilImage image);

void
xil_colorspace_set_name(XilColorspace, char*);

void
xil_colorspacelist_set_name(XilColorspaceList, char*);

/*
 *  Get the state that was used to create the given object.
 */
XilSystemState
xil_get_state(XilImage);

XilSystemState
xil_imagetype_get_state(XilImageType);

XilSystemState
xil_lookup_get_state(XilLookup);

XilSystemState
xil_cis_get_state(XilCis);

XilSystemState
xil_dithermask_get_state(XilDitherMask);

XilSystemState
xil_kernel_get_state(XilKernel);

XilSystemState
xil_sel_get_state(XilSel);

XilSystemState
xil_roi_get_state(XilRoi);

XilSystemState
xil_histogram_get_state(XilHistogram);

XilSystemState
xil_storage_get_state(XilStorage);

XilSystemState
xil_colorspace_get_state(XilColorspace);

XilSystemState
xil_colorspacelist_get_state(XilColorspaceList);

/*
 *  XilColorspaceList object methods
 */
XilColorspaceList
xil_colorspacelist_create(XilSystemState,
                          XilColorspace*,
                          unsigned int);

void
xil_colorspacelist_destroy(XilColorspaceList);


/*
 *  XilColorspace object methods
 */
XilColorspace
xil_colorspace_create(XilSystemState,
                      XilColorspaceType,
                      void*);

void
xil_colorspace_destroy(XilColorspace);

XilColorspaceType
xil_colorspace_get_type(XilColorspace);

/*
 *  Methods for the XilStorage object
 */
XilStorage
xil_storage_create(XilSystemState, XilImage);

void
xil_storage_destroy(XilStorage);

Xil_boolean
xil_storage_is_type(XilStorage, XilStorageType);

unsigned int
xil_storage_get_scanline_stride(XilStorage, unsigned int);

unsigned int
xil_storage_get_pixel_stride(XilStorage, unsigned int);

unsigned int
xil_storage_get_band_stride(XilStorage);

unsigned int
xil_storage_get_offset(XilStorage, unsigned int);

void*
xil_storage_get_data(XilStorage, unsigned int);

void
xil_storage_get_coordinates(XilStorage, unsigned int*, unsigned int*);

void
xil_storage_set_scanline_stride(XilStorage, unsigned int, unsigned int);

void
xil_storage_set_pixel_stride(XilStorage, unsigned int, unsigned int);

void
xil_storage_set_band_stride(XilStorage, unsigned int);

void
xil_storage_set_offset(XilStorage, unsigned int, unsigned int);

void
xil_storage_set_data(XilStorage   ,
                     unsigned int ,
                     void*        );

void
xil_storage_set_data_release(XilStorage,
                             XilDataReleaseFuncPtr, 
                             void*);

void
xil_storage_set_coordinates(XilStorage  ,
                            unsigned int,
                            unsigned int);

void
xil_color_correct(XilImage          src,
                  XilImage          dst,
                  XilColorspaceList cslist);

#endif
