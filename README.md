# kat
**kat** or **kat.cfg** is a simpler and more minimalistic C port of [dog.cfg](https://github.com/jstmaxlol/dog.cfg) \
C++ library used to manage simple `KEY=VALUE` configuration files.

## API
* `kat.create(path)` - creates a new configuration file
* `kat.add(key, val, path)` - adds a new `key=value`
* `kat.addComment(str, path)` - add a new `#` comment
* `kat.read(key, path, buffer, buffer_size)` - read a key's value to a buffer
* `kat.del(key, path)` - delete a key with its value
* `kat.edit(key, new_value, path)` - edit a key's value
