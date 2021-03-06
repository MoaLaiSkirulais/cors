# ------------------------------
# params
# ------------------------------
export gdb=0;
for var in "$@"; do
	if [[ "$var" = "-gdb" ]]; then gdb=1; fi	
done

# ------------------------------
# clean
# ------------------------------
rm *.o
rm *.exe

# ------------------------------
# make
# ------------------------------
echo "make"
make -f Makefile.test

# ------------------------------
# exec
# ------------------------------
echo "exec"
if [ $gdb = 1 ]; then #gdb	
	gdb ./main.exe
else
	./main.exe
fi

# ------------------------------
# ------------------------------
