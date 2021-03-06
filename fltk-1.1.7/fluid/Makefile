#
# "$Id: Makefile 4759 2006-01-15 19:26:08Z mike $"
#
# FLUID makefile for the Fast Light Tool Kit (FLTK).
#
# Copyright 1998-2005 by Bill Spitzak and others.
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the GNU Library General Public
# License as published by the Free Software Foundation; either
# version 2 of the License, or (at your option) any later version.
#
# This library is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
# Library General Public License for more details.
#
# You should have received a copy of the GNU Library General Public
# License along with this library; if not, write to the Free Software
# Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
# USA.
#
# Please report all bugs and problems on the following page:
#
#      http://www.fltk.org/str.php
#

CPPFILES = \
	CodeEditor.cxx \
	Fl_Function_Type.cxx \
	Fl_Group_Type.cxx \
	Fl_Menu_Type.cxx \
	Fl_Type.cxx \
	Fl_Widget_Type.cxx \
	Fl_Window_Type.cxx \
	Fluid_Image.cxx \
	about_panel.cxx \
	align_widget.cxx \
	alignment_panel.cxx \
	code.cxx \
	factory.cxx \
	file.cxx \
	fluid.cxx \
	function_panel.cxx \
	template_panel.cxx \
	undo.cxx \
	widget_panel.cxx

################################################################

OBJECTS = $(CPPFILES:.cxx=.o)

include ../makeinclude

all:	$(FLUID) fluid$(EXEEXT)

fluid$(EXEEXT):		$(OBJECTS) ../lib/$(LIBNAME) ../lib/$(FLLIBNAME) \
			../lib/$(IMGLIBNAME)
	echo Linking $@...
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LINKFLTKFORMS) $(LINKFLTKIMG) $(LDLIBS)
	$(POSTBUILD) $@ ../FL/mac.r
	$(CP) $@ fluid.app/Contents/MacOS

fluid-shared$(EXEEXT):	$(OBJECTS) ../src/$(DSONAME) ../src/$(FLDSONAME) \
			../src/$(IMGDSONAME)
	echo Linking $@...
	$(CXX) $(CXXFLAGS) -o $@ $(OBJECTS) $(LINKSHARED) $(LDLIBS)
	$(POSTBUILD) $@ ../FL/mac.r

clean:
	-$(RM) *.o core.* *~ *.bck *.bck
	-$(RM) core fluid$(EXEEXT) fluid-shared$(EXEEXT)

depend:	$(CPPFILES)
	makedepend -Y -I.. -f makedepend $(CPPFILES)

# Automatically generated dependencies...
include makedepend

install: all
	echo "Installing FLUID in $(DESTDIR)$(bindir)..."
	-$(MKDIR) $(DESTDIR)$(bindir)
	$(CP) $(FLUID) $(DESTDIR)$(bindir)/fluid$(EXEEXT)
	$(STRIP) $(DESTDIR)$(bindir)/fluid$(EXEEXT)
	$(DESTDIR)$(bindir)/fltk-config --post $(DESTDIR)$(bindir)/fluid$(EXEEXT)
	$(CHMOD) 755 $(DESTDIR)$(bindir)/fluid$(EXEEXT)

install-linux:
	-$(MKDIR) $(DESTDIR)/usr/share/applnk/Development
	$(CP) fluid.desktop  $(DESTDIR)/usr/share/applnk/Development
	for size in 16 32 48 64 128; do \
		if test ! -d $(DESTDIR)/usr/share/icons/hicolor/$${size}x$${size}/apps; then \
			$(MKDIR) $(DESTDIR)/usr/share/icons/hicolor/$${size}x$${size}/apps; \
		fi; \
		$(CP) icons/fluid-$$size.png $(DESTDIR)/usr/share/icons/hicolor/$${size}x$${size}/apps/fluid.png; \
	done
	-$(MKDIR) $(DESTDIR)/usr/share/mimelnk/application
	$(CP) x-fluid.desktop  $(DESTDIR)/usr/share/mimelnk/application

install-osx:
	-$(MKDIR) $(DESTDIR)/Applications/fluid.app
	-$(MKDIR) $(DESTDIR)/Applications/fluid.app/Contents
	$(CP) fluid.app/Contents/Info.plist $(DESTDIR)/Applications/fluid.app/Contents/Info.plist
	$(CP) fluid.app/Contents/PkgInfo $(DESTDIR)/Applications/fluid.app/Contents/PkgInfo
	-$(MKDIR) $(DESTDIR)/Applications/fluid.app/Contents/MacOS
	$(LN) $(bindir)/fluid $(DESTDIR)/Application/fluid.app/Contents/MacOS/fluid
	-$(MKDIR) $(DESTDIR)/Applications/fluid.app/Contents/Resources
	$(CP) fluid.app/Contents/Resources/fluid.icns $(DESTDIR)/Applications/fluid.app/Contents/Resources

uninstall:
	$(RM) $(DESTDIR)$(bindir)/fluid$(EXEEXT)

uninstall-linux:
	$(RM) $(DESTDIR)/usr/share/applnk/Development/fluid.desktop
	$(RM) $(DESTDIR)/usr/share/icons/hicolor/*/fluid.png
	$(RM) $(DESTDIR)/usr/share/mimelnk/application/x-fluid.desktop

uninstall-osx:
	$(RM) -r $(DESTDIR)/Applications/fluid.app


#
# Note: The rebuild target can only be used if you have the original .fl
#       files.  This is normally only used by the FLTK maintainers...
#

rebuild:
	./fluid -c about_panel.fl
	./fluid -c alignment_panel.fl
	./fluid -c function_panel.fl
	./fluid -c print_panel.fl
	./fluid -c template_panel.fl
	./fluid -c widget_panel.fl

#
# End of "$Id: Makefile 4759 2006-01-15 19:26:08Z mike $".
#
