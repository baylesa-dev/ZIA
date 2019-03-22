# Configuration

## Overview

Configuration file define which module Zia have to load. You can change and reload a configuration file *'on-the-fly'*, without restarting nor recompiling the server.

Configurations files are written in *__.xml__*, so they are more reader-friendly.

## Default values

- **name**: *Default Zia*
- **version**: *0.0.0*
- **port**: *4242*

## Create your own configuration

You can create your own configuration file using *__.xml__*.

You should pass your configuration file as below :

```bash
./zia --config "./my_config.xml"
```

## Configuration example

```xml
<server name="Zia" version="1.0.0" port="1234">
    <modules>
        <PHPModule></PHPModule>
        <DEBUGModule></DEBUGModule>
    </modules>
</server>
```
