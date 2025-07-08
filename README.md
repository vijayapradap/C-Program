### 📦 Docker & IoT Edge Commands

<details>
<summary>📋 Show full iotedge + docker setup commands</summary>

```bash
# Install Microsoft packages and iotedge
wget https://packages.microsoft.com/config/ubuntu/22.04/packages-microsoft-prod.deb -O packages-microsoft-prod.deb
sudo dpkg -i packages-microsoft-prod.deb
rm packages-microsoft-prod.deb
sudo apt-get update
sudo apt-get install moby-engine
sudo apt-get install aziot-edge=1.4.33-1 aziot-identity-service=1.4.8-1

# Configure and apply iotedge
sudo iotedge config mp --connection-string "<your-iothub-connection-string>" --force
sudo iotedge config apply -c '/etc/aziot/config.toml'
sudo iotedge system restart
sudo iotedge list
```

</details>

---

### 📷 Webcam & Image Capture

```bash
uvccapture -q85 -x1920 -y1080 -B20 -C5 -ooutput.jpg
fswebcam -r 3840x3104 --jpeg 85 -D 1 web-cam-shot.jpg
fswebcam -r 3840x3104 --fps 15 -F 3 --jpeg 85 --no-timestamp web-cam-shot.jpg
```

---

### 🐳 Docker Snippets

```bash
# List containers
iotedge list | grep 'CookingService' | awk '{print $1}'

# Enter container shell
sudo docker exec -it <container_id> bash

# Remove all containers
sudo docker rm $(docker container ps -q) -f
```

---

### 🧰 Dockerfile Example (ARM64v8)

```Dockerfile
FROM ubuntu:20.04
RUN apt-get update && apt-get install -y x11-apps dbus-x11 && rm -rf /var/lib/apt/lists/*
ENV DISPLAY=:0
ENTRYPOINT ["/bin/bash"]
```

---

### 🔐 ACR & Azure Login

```bash
sudo docker login -u <username> -p <password> <registry>.azurecr.io
```

---

### 🗃 OTA Setup Commands

```bash
mkdir /etc/smart_oven/ota
sudo chown 1000 /etc/smart_oven/ota/
sudo chmod 700 /etc/smart_oven/ota/
```

---

### 🔁 Init Scripts

```bash
sudo chown root:root /etc/init.d/ota_runner.sh
sudo chmod 755 /etc/init.d/ota_runner.sh
sudo update-rc.d ota_runner.sh defaults
```

### 🧪 Firmware OTA JSON Structure

```json
{
  "route_message_id": 1001,
  "ota_update": {
    "is_iot_edge": false,
    "firmware_name": "hw_lib",
    "firmware_version": "V1_1",
    "update_description": "brief information about update",
    "blob_url": "https://<blob-url>",
    "md5sum_checksum": "e7671c1d402a68a3dc1b0e8a603cb048",
    "user_acceptance": true,
    "timeout_time": 60,
    "fail_retry_count": 3,
    "fail_retry_interval": 30
  }
}
```

---

### 🧠 Sample C Snippet

```c
void fun(int **p) {
 static int q = 10;
 *p = &q;
}
int main() {
 int r = 20;
 int *p = &r;
 fun(&p);
 printf("%d", *p);
 return 0;
}
```

---


```markdown

```bash
iotedge list | grep 'CookingService' | awk '{print $1}'
```

### Docker Container Directory

```bash
/var/lib/docker/containers
```

### Access Container Shell

```bash
sudo docker exec -it ca4ec361be29 bash
```

### Remove All Containers

```bash
sudo docker rm $(docker container ps -q) -f
```

## Webcam Capture Commands

### Capture Image with `uvccapture`

```bash
uvccapture -q85 -x1920 -y1080 -B20 -C5 -ooutput.jpg
```

### Capture Image with `fswebcam`

```bash
fswebcam -r 3840x3104 --jpeg 85 -D 1 web-cam-shot.jpg
```

### Capture Image with `fswebcam` (Alternative)

```bash
fswebcam -r 3840x3104 --fps 15 -F 3 --jpeg 85 --no-timestamp web-cam-shot.jpg
```

## Network Status

### Display Listening Ports

```bash
sudo netstat -tulpn
```

## Dockerfile for ARM64v8 Architecture

```Dockerfile
# Use an official Ubuntu base image
FROM ubuntu:20.04

# Install necessary packages
RUN apt-get update && apt-get install -y \
    x11-apps \
    dbus-x11 \
    && rm -rf /var/lib/apt/lists/*

# Set environment variables for display access
ENV DISPLAY=:0

# Set the entrypoint to a shell
ENTRYPOINT ["/bin/bash"]
```

## Useful Links

- [Microchip C Programming Callbacks](https://mu.microchip.com/c-programming-callbacks)
- [Advanced C Programming](https://mu.microchip.com/advanced-c-programming/784729)
- [myWiki](https://github.com/vijayapradap/Git_Workspace/wiki)
- [Chessman](https://mohitmishra786.github.io/chessman/)
```
