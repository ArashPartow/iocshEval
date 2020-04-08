# iocshEval

Use the evaluation of mathematical expression to set environment variables.

So far only one iocshFunction is implemented `epicsEnvSetTernary`. As the name suggests, this function will set an environment variable based on the evaluation of a ternary expression.

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
