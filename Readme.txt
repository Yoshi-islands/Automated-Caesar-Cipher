
 
*********************************
frequecy_table.c : 
*********************************
- Assuming for the letter count  we are counting everything within a valid ASCII range of letters. 
This count only includes letters A/a until z/Z and nothing else
( the ascii range of  64 - 122 )
- Assuming that character count is only letters and that character count which includes every character 
( including newline, termination etc.. ) 
- Assuming that the maximum length of a word can be 45 characters
- Assuming in the main, that a filename can have a maximum length of 20 characters ( This is for the flags )
- Assuming that stdin in part 1 also ends with control d for stdin ( which indicates the EOF )

*********************************
decode.c : 
*********************************
- Assuming that text_frequency is an array which in the main ( not specified )
- Assuming that chi_sq can take in more parameters ( As told by the TA's )
- Assuming that the encode_shift function can take in more parameters ( not specified, only return value is specified )
- Assuming that the -t flag ( for printing frequency ) is meant to be printed seperatley than the -x flag ( chi calculations )
- Assuming that we can clarify "encoding shift" and "decoding shift" for the user to differentiate for -s and -S flags 
- Assuming that we are able to print within a function
- Assuming that the flags cannot be used such as, where theres a space between seperate flags ( -st -xS etc..) 
- Assuming that we leave everything else that isn't letters untouched
- Assuming that we leave already decoded files as decoded, ( as there is nothing to encode )
- Assuming some error cases which are printed to stderr based on flags
- Assuming that for encode_shift we are meant to have a condition for >= 0.5 and text < 200 ( as indicated )

*********************************
copyrecords.c
*********************************
- Assuming that the records are in order ( of the structure described)
- Assuming that for the records we need to print them to stdout as normal text
- Assuming that for the records we need to print them to binary ( for the file )
- Assuming that we can still reverse even if we have the -F flag 
- Assuming that when we reverse we are reading records from the end of the file ( structure is the same throughout )
- Assuming formatting for the records when printing them is allowed ( ie; names of things and decimal places)
( Attempted to finish the reverse flag )


Compilation for the makefile : 
Files : frequecy_table.c , decode.c and copyrecords.c 
make clean
make all
( compiled )
./frequecy_table <flags> 
./decode <flags> 
./copyrecords <flags>