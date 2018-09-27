all: \
	$(ROOTBUILD)/eppos_ApiServer.o \
	archive 


$(ROOTBUILD)/eppos_ApiServer.o: ../eppos_ApiServer.c ../eppos_ApiServer.h
	$(GCC) $(INC) $(FLAGS) -c $< -o $@

archive: 
	@ar -cr $(ROOTBUILD)/eppos_ApiServer.a \
		$(ROOTBUILD)/eppos_ApiServer.o \
