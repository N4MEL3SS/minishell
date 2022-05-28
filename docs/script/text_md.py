def file_md(f_md, line_md):
    f_md.write("# " + line_md + "\n\n\n\n")
    f_md.write("```\n")
    f_md.write("\n")
    f_md.write("```\n")
    f_md.write("\n")
    f_md.write("[man " + line_md + "]()\n")
    f_md.close()


with open("allow_ft.txt", "r") as file:
    for line in file:
        line = line.replace("\n", "")
        file_md(open("md/" + line + ".md", "w"), line)
