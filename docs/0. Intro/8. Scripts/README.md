NGOS
====

0.8. Scripts
------------

There are several scripts can be found in the [scripts](../../../scripts/) folder.

### add_rc_version_tag.sh

This script helps to add tag for new RC version.<br/>
It should be called from the project root directory.

Example:

```sh
./scripts/add_rc_version_tag.sh
```

### add_version_tag.sh

This script helps to add tag for new version.<br/>
It should be called from the project root directory.

Example:

```sh
./scripts/add_version_tag.sh
```

### commit.sh

This script can be used to simplify interaction with the Git.<br/>
You can use it for fast committing all of your changes.<br/>
This script should be called from the project root directory.

Here is the usage:

```sh
./scripts/commit.sh MESSAGE
```

Example:

```sh
./scripts/commit.sh "My dear commit"
```

### pull.sh

This script can be used to simplify interaction with the Git.<br/>
Equivalent for `git pull`

Example:

```sh
./scripts/pull.sh
```

### push.sh

This script can be used to simplify interaction with the Git.<br/>
Equivalent for `git push origin master --tags`

Example:

```sh
./scripts/push.sh
```

### update_ngos_files.sh

Please use this script to recreate [ngos.files](../../../ngos.files) file after adding or removing files.<br/>
This script should be called from the project root directory.

Example:

```sh
./scripts/update_ngos_files.sh
```
