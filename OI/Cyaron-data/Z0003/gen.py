from cyaron import *
for i in range(1, 4) :
    data = IO(file_prefix = "data/", data_id = i)
    data.input_writeln(String.random(25,charset="0123456789()"))
    data.output_gen("std.exe")