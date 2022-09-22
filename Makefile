DIR=.
OUT=launcher
CFLAGS=-O2 -Os -Wall `wx-config --cxxflags`
LDFLAGS=-s

LIBS=`wx-config --libs`
#LIBS=-pthread   /usr/lib/libwx_x11univu_richtext-2.8.a /usr/lib/libwx_x11univu_aui-2.8.a /usr/lib/libwx_x11univu_xrc-2.8.a /usr/lib/libwx_x11univu_qa-2.8.a /usr/lib/libwx_x11univu_html-2.8.a /usr/lib/libwx_x11univu_adv-2.8.a /usr/lib/libwx_x11univu_core-2.8.a /usr/lib/libwx_baseu_xml-2.8.a /usr/lib/libwx_baseu_net-2.8.a /usr/lib/libwx_baseu-2.8.a -lpangox-1.0 -lpangoxft-1.0 -lpangoft2-1.0 -lXft -lpango-1.0 -lfreetype -lfontconfig -lgobject-2.0 -lgmodule-2.0 -lglib-2.0 -lX11 -lXext -lXinerama -lpng -lz -ldl -lm

OBJS=launcherApp.o launcherMain.o

.PHONY: clean all clean-src

all : $(OUT)

$(OUT) : $(OBJS)
	$(CXX) $(OBJS) -o $(OUT) $(LIBS) $(LDFLAGS)

%.o : $(DIR)/src/%.cpp
	$(CXX) -c $(CFLAGS) -o $@ $<  
	
clean:
	@echo Cleaning...
	rm -f $(OUT) $(OBJS)
	rm -f *~
	@echo Done.

clean-src:
	@echo Cleaning source...
	rm -f `find $(DIR) -name \*~`
	@echo Done.
