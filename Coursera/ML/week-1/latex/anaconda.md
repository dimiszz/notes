### Set-up a conda environment

1. Open a Command Prompt (Windows) or a terminal (macOS or Linux)

    *Note: If you chose not to add Anaconda to PATH during Anaconda installation above, you will need to use the Anaconda Command Prompt instead.*
2. Create a conda environment for PyTorch:
    ```Shell
    conda create -n pytorch python=3.6
    ```
3. Activate your new environment:

    ```Shell 
    conda activate pytorch
    ```
4. Install some supporting dependencies
    ```Shell
    conda install h5py imageio jupyter matplotlib numpy tqdm
    ```

5. Install either the CPU version or GPU version of PyTorch:

    CPU: *(Recommended as sufficient for this class)*
    ```Shell
    # Windows/Linux
    conda install pytorch torchvision cpuonly -c pytorch
    
    # macOS
    conda install pytorch torchvision -c pytorch
    ```
    
    GPU: (You'll also need to install some [Nvidia software](https://developer.nvidia.com/cuda-10.1-download-archive-base))
    ```Shell
    # Windows/Linx, assuming CUDA 10.1
    conda install pytorch torchvision cudatoolkit=10.1 -c pytorch
    
    # macOS 
    # Trickier. May require installing from source. See PyTorch docs.
    ```

    *Note: If you have GPUs available, you should use the GPU version for any serious research or application, as it can be significantly faster. For the purposes of this demo though, the CPU version is sufficent.*