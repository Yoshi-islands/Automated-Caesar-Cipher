all: frequency_table decode copyrecords

letter_count.o: letter_count.c
	gcc -ansi -Wall -c letter_count.c

add_letters.o: add_letters.c
	gcc -ansi -Wall -c add_letters.c

create_freq_table.o: create_freq_table.c
	gcc -ansi -Wall -c create_freq_table.c

frequency_table.o: frequency_table.c
	gcc -ansi -Wall -c frequency_table.c

file_size.o: file_size.c
	gcc -ansi -Wall -c file_size.c

frequency_table: frequency_table.o letter_count.o add_letters.o create_freq_table.o file_size.o
	gcc -ansi -Wall -o frequency_table frequency_table.o letter_count.o add_letters.o create_freq_table.o file_size.o

offset.o: offset.c
	gcc -ansi -Wall -c offset.c

encode.o: encode.c
	gcc -ansi -Wall -c encode.c

chi_sq.o: chi_sq.c
	gcc -ansi -Wall -c chi_sq.c

encode_shift.o: encode_shift.c
	gcc -ansi -Wall -c encode_shift.c

to_decode.o: to_decode.c
	gcc -ansi -Wall -c to_decode.c

decode.o: decode.c
	gcc -ansi -Wall -c decode.c

decode: decode.o offset.o letter_count.o add_letters.o create_freq_table.o encode.o chi_sq.o encode_shift.o to_decode.o file_size.o
	gcc -ansi -Wall -o decode decode.o offset.o letter_count.o add_letters.o create_freq_table.o encode.o chi_sq.o encode_shift.o to_decode.o file_size.o

copyrecords.o: copyrecords.c
	gcc -ansi -Wall -c copyrecords.c

copyrecords: copyrecords.o file_size.o letter_count.o add_letters.o create_freq_table.o encode.o chi_sq.o encode_shift.o to_decode.o offset.o
	gcc -ansi -Wall -o copyrecords copyrecords.o file_size.o letter_count.o add_letters.o create_freq_table.o encode.o chi_sq.o encode_shift.o to_decode.o offset.o

clean: 
	rm frequency_table decode copyrecords *.o
