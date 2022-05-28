site = open("site.md", "w")

with open("/Users/celadia/school21/minishell/docs/script/allow_ft.txt", "r") as file:
    for line in file:
        site.write("####" + line[:-1] + "\n")
        site.write("[" + line[:-1] + "]")
        site.write("(https://www.opennet.ru/man.shtml?topic=" + line[:-1] + ")\n")
        site.write("\n")

site.close()
