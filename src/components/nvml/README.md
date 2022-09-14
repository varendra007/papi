# NVML Component

The NVML (NVIDIA Management Library) component exposes hardware management
counters and controls for NVIDIA GPUs, such as power consumption, fan speed and
temperature readings; it also allows capping of power consumption.

* [Enabling the NVML Component](#markdown-header-enabling-the-nvml-component)
* [Environment Variables](#markdown-header-environment-variables)
* [Known Limitations](#markdown-header-known-limitations)
* [FAQ](#markdown-header-faq)
***
## Enabling the NVML Component

To enable reading or writing of NVML counters the user needs to link
against a PAPI library that was configured with the NVML component enabled.
As an example the following command: `./configure --with-components="nvml"`
is sufficient to enable the component.

Typically, the utility `papi_components_avail` (available in
`papi/src/utils/papi_components_avail`) will display the components available
to the user, and whether they are disabled, and when they are disabled why.

## Environment Variables
NVML uses the same Environment variable as the CUDA component; `PAPI_CUDA_ROOT`.

Example:

    export PAPI_CUDA_ROOT=/usr/local/cuda-10.1

Within PAPI_CUDA__ROOT, we expect the following standard directories:

    PAPI_CUDA_ROOT/include
    PAPI_CUDA_ROOT/lib64
    PAPI_CUDA_ROOT/extras/CUPTI/include
    PAPI_CUDA_ROOT/extras/CUPTI/lib64

For the NVML component to be operational at runtime, it must find the following dynamic libraries:

    libcuda.so
    libcudart.so
    libnvidia-ml.so

If those libraries cannot be found or some of those are stub libraries in the standard `PAPI_CUDA_ROOT` subdirectories, you have to add the correct paths, e.g. `/usr/lib64` or `/usr/lib` to `LD_LIBRARY_PATH`, separated by colons `:`. This can be set using export; e.g. 

    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/WhereLib1CanBeFound:/WhereLib2CanBeFound


## Known Limitations

* Some systems require `sudo` (superuser) status in order to set or read 
power limits; such permissions are typically granted by your sysadmin.
***

## FAQ

1. [Unusual installations](#markdown-header-unusual-installations)

## Unusual installations
Three libraries are required for the PAPI NVML component. `libcuda.so`,
`libcudart.so' (The CUDA run-time library), and `libnvidia-ml.so`.  

For the NVML component to be operational, it must find the dynamic libraries
mentioned above. If they are not found in the standard `PAPI_CUDA_ROOT`
subdirectories mentioned above, the component looks in the Linux default
directories listed by `/etc/ld.so.conf`, usually `/usr/lib64`, `/lib64`,
`/usr/lib` and `/lib`. 

The system will also search the directories listed in `LD_LIBRARY_PATH`,
separated by colons `:`. This can be set using export; e.g. 

    export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/WhereLib1CanBeFound:/WhereLib2CanBeFound
