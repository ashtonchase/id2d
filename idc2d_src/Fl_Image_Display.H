//
// "$Id: Fl_Image_Display.H 322 2005-01-23 03:55:19Z easysw $"
//
// Image display widget header file for the Fast Light Tool Kit (FLTK).
//
// Copyright 2002-2005 by Michael Sweet.
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or (at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//

#ifndef Fl_Image_Display_H
#  define Fl_Image_Display_H
#  include <FL/Fl_Group.H>
#  include <FL/Fl_Scrollbar.H>
#  include <FL/Fl_Shared_Image.H>


enum
{
  FL_IMAGE_PAN,
  FL_IMAGE_ZOOM_IN,
  FL_IMAGE_ZOOM_OUT,
  FL_IMAGE_CLICK
};


class FL_EXPORT Fl_Image_Display : public Fl_Group
{
  static uchar		gamma_lut_[256];

  int			mode_;
  int           send_coords;
  int           cursor_;
  int           inside_;
  Fl_Shared_Image	*value_;
  Fl_Scrollbar		xscrollbar_;
  Fl_Scrollbar		yscrollbar_;
  float			factor_;
  int			xsize_;
  int			xstep_;
  int			xmod_;
  int			ysize_;
  int			start_ex_, start_ey_;
  int			start_x_, start_y_;
  int			mouse_x_, mouse_y_;
  int			last_x_, last_y_;

  static void	image_cb(void *p, int X, int Y, int W, uchar *D);
  static void	scrollbar_cb(Fl_Widget *w, void *d);
  void		update_mouse_xy();
  void		update_scrollbars();

  protected:

  void		draw();
  void (*cb)(const int ax, const int ay);


  public:

  Fl_Image_Display(int X, int Y, int W, int H, const char *L = 0);
  ~Fl_Image_Display();

  int			handle(int event);
  void			mode(int m) { mode_ = m; }
  int			mode() const { return mode_; }
  int			mouse_x() const { return mouse_x_; }
  int			mouse_y() const { return mouse_y_; }
  void			position(int X, int Y);
  void			resize(int X, int Y, int W, int H);
  void			scale(float factor);
  float			scale() const { return factor_; }
  int			start_x() const { return start_x_; }
  int			start_y() const { return start_y_; }
  void			value(Fl_Shared_Image *v, float factor = 0.0f);
  Fl_Shared_Image	*value() { return value_; }
  int			xposition() { return xscrollbar_.value(); }
  int			yposition() { return yscrollbar_.value(); }
  void          set_callback(void (*fcb)(const int cx, const int cy));
  void          set_send_coords(const int yes) { send_coords = yes; };
 

  static void		set_gamma(float val = 2.2);
};


#endif // !Fl_Image_Display_H

//
// End of "$Id: Fl_Image_Display.H 322 2005-01-23 03:55:19Z easysw $".
//
