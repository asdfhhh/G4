CC = g++
CPPFLAGS += -I`root-config --incdir`
LDLIBS += `root-config --glibs`

data_ana: data_ana.cpp  ParticleDis.cxx ParticleDis.h
	$(CC) $(LDLIBS) $(CPPFLAGS) -o $@  data_ana.cpp  ParticleDis.cxx 

.PHONY:clean 
clean:
	rm -f data_ana 

