# access

**access** - проверяет, имеет ли процесс права на чтение или запись, или же просто проверяет,
существует ли файл (или другой объект файловой системы), с именем pathname. Если pathname является символьной ссылкой,
то проверяются права доступа к файлу, на который она ссылается.

```
#include <unistd.h>

int access(const char *pathname, int mode);
```

[man access](https://www.opennet.ru/man.shtml?topic=access)
