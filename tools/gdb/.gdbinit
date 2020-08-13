python
import os
import re
import subprocess



def relocate_sections(filename, address):
    process = subprocess.Popen(["readelf", "-S", os.path.expanduser(filename)], stdout = subprocess.PIPE)

    sections     = []
    text_address = "0"



    lines = process.stdout.readlines()

    for i in range(len(lines)):
        line = lines[i].decode("utf-8").strip()

        if not line.startswith("[") or line.startswith("[Nr]"):
            continue

        line = line + " " + lines[i + 1].decode("utf-8").strip()

        line = re.sub(r' +', ' ', line)
        line = re.sub(r'\[ *(\d+)\]', '\g<1>', line)

        fields_names  = ["number", "name", "type", "address", "offset", "size", "entsize", "flags", "link", "info", "align"]
        fields_values = line.split(" ")

        sec = dict(zip(fields_names, fields_values))

        if sec["number"] == "0":
            continue

        if sec["name"] == ".text":
            text_address = sec["address"]
        else:
            sections.append(sec)



    return (text_address, sections)



class AddSymbolFileAll(gdb.Command):
    def __init__(self):
        super(AddSymbolFileAll, self).__init__("add-symbol-file-all", gdb.COMMAND_USER)
        self.dont_repeat()



    def invoke(self, arg, from_tty):
        argv = gdb.string_to_argv(arg)
        filename = argv[0]

        if len(argv) > 1:
            offset = int(str(gdb.parse_and_eval(argv[1])), 0) % 2**64
        else:
            offset = 0

        (text_address, sections) = relocate_sections(filename, offset)

        cmd = "add-symbol-file %s 0x%016llX" % (filename, (int(text_address, 16) + offset) % 2**64)

        for section in sections:
            if "A" in section["flags"]:
                cmd += " -s %s 0x%016llX" % (section["name"], (int(section["address"], 16) + offset) % 2**64)

        gdb.execute(cmd)



class RemoveSymbolFileAll(gdb.Command):
    def __init__(self):
        super(RemoveSymbolFileAll, self).__init__("remove-symbol-file-all", gdb.COMMAND_USER)
        self.dont_repeat()



    def invoke(self, arg, from_tty):
        argv = gdb.string_to_argv(arg)
        filename = argv[0]

        if len(argv) > 1:
            offset = int(str(gdb.parse_and_eval(argv[1])), 0) % 2**64
        else:
            offset = 0

        (text_address, _) = relocate_sections(filename, offset)

        cmd = "remove-symbol-file -a 0x%016llX" % ((int(text_address, 16) + offset) % 2**64)
        gdb.execute(cmd)



AddSymbolFileAll()
RemoveSymbolFileAll()
end
