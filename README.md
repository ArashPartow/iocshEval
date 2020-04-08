# iocshEval

Use the evaluation of mathematical expression to set environment variables.

So far only one iocshFunction is implemented `epicsEnvSetTernary`. As the name suggests, this function will set an environment variable based on the evaluation of a ternary expression.

## exprTK

This module uses [exprTK](https://github.com/ArashPartow/exprtk) for expression evaluation. Please refer to the manual for examples.

## Example

### basic proof of principle

```iochSh
epicsEnvSetTernary("myEnvVar", "5>4", "yes", "no")
```
This will set `myEnvVar` to _yes_

### more useful example

In this example a specific script will be executed depending on whether _SYS_ID_ is 64 or 76 or not.

```
epicsEnvSet(SYS_ID, 64)
echo ${SYS_ID}

epicsEnvSetTernary("myEnvVar", "${SYS_ID}==64 or ${SYS_ID}==76", "addDeviceType1.iocsh", "addDeviceType2.iocsh")

runScript("${myEnvVar}")
```

### real life example

Assume all mirrors in SwissFEL optics have the same tripod for vertical, roll an pitch motion. Only difference is the orientation of the legs. Thus, the kinematics for complex motion is different.
The add_device.cmd subsequently uses `runScript` to load the respective motor and kinematics configuration.
Instead of having separate modules, or cryptic macros, the filename of can be stored in an environment variable automatically, based on the _SYS_ macro.

```
epicsEnvSet("SYS", "SATOP11-OOMV094")
epicsEnvSetTernary("TRIPOD_CONFIG", "'OOMV' in '${SYS}'", "vertical.cfg", "horizontal.cfg")
#- load tripod configuration
runScript("${TRIPOD_CONFIG}")
```
