# closedir

Функция **closedir** закрывает поток, связанный с каталогом dir. Описатель потока dir будет недоступен после вызова этой функции.

```
#include <dirent.h>

int closedir(DIR *dir);
```

[man closedir](https://www.opennet.ru/man.shtml?topic=closedir)
