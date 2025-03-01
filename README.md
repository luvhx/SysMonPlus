# SysMonPlus
SysMon++ - Linux 服务器智能监控系统
https://img.shields.io/badge/license-MIT-blue.svg
https://img.shields.io/badge/python-3.8%2B-green
https://img.shields.io/badge/C++-17-red

SysMon++ 是一个全栈式 Linux 服务器监控解决方案，结合高性能系统级数据采集和现代化的 Web 可视化界面，提供从底层监控到上层展示的完整运维工具链。

功能特性
🚀 ​实时系统监控
CPU/Memory/Disk 使用率
网络流量分析
进程资源追踪
🔔 ​智能报警系统
阈值触发报警
邮件/Slack/Webhook 通知
报警历史记录
📊 ​数据可视化
实时动态图表
历史数据回溯
多服务器对比
🔐 ​安全控制
JWT 认证
RBAC 权限管理
操作审计日志
🐳 ​容器化部署
Docker 一键部署
Kubernetes 就绪
自动伸缩支持
系统架构
mermaid
graph TD
    A[Agent] -->|HTTP/WebSocket| B(Backend)
    B -->|REST API| C[Frontend]
    C -->|用户交互| D[Admin]
    A -->|数据存储| E[(InfluxDB)]
    B -->|报警触发| F[SMTP/Slack]
    style A fill:#4CAF50,stroke:#388E3C
    style B fill:#2196F3,stroke:#1976D2
    style C fill:#FF9800,stroke:#F57C00
快速开始
前置要求
Linux 内核 4.15+
Docker 20.10+
docker-compose 2.5+
Docker 部署
bash
# 克隆仓库
git clone https://github.com/yourusername/SysMonPlus.git
cd SysMonPlus

# 启动服务
docker-compose up -d
访问地址：

前端界面：http://localhost:3000
API 文档：http://localhost:5000/docs
监控看板：http://localhost:3000/dashboard
从源码构建
1. 安装依赖
bash
# 系统依赖
sudo apt install -y build-essential cmake libssl-dev

# Python 依赖
cd backend
pip install -r requirements.txt

# Node.js 依赖
cd ../frontend
npm install
2. 编译 Agent
bash
cd agent
mkdir build && cd build
cmake .. -DCMAKE_BUILD_TYPE=Release
make -j$(nproc)
sudo make install
3. 配置服务
创建 .env 文件：

ini
# backend/.env
MONITOR_INTERVAL=5
DATABASE_URL=influxdb://localhost:8086/sysmon
JWT_SECRET_KEY=your-secret-key
4. 启动系统
bash
# 启动 Agent
sudo systemctl start sysmon-agent

# 启动后端
cd backend && flask run --port=5000

# 启动前端
cd frontend && npm start
API 文档
基础端点
端点	方法	描述
/api/metrics	GET	获取实时监控数据
/api/alerts	POST	创建报警规则
/api/history	GET	查询历史数据
示例请求
bash
curl -X GET "http://localhost:5000/api/metrics" \
     -H "Authorization: Bearer YOUR_JWT_TOKEN"
响应示例：

json
{
  "cpu": 23.45,
  "memory": 68.32,
  "disk": "/ 55%, /home 32%",
  "network": {"in": "12MB/s", "out": "8MB/s"},
  "timestamp": "2023-09-20T14:30:00Z"
}
贡献指南
欢迎通过以下方式参与贡献：

Fork 项目仓库
创建特性分支 (git checkout -b feature/awesome-feature)
提交更改 (git commit -am 'Add awesome feature')
推送分支 (git push origin feature/awesome-feature)
创建 Pull Request
代码规范：

C++ 遵循 Google Style Guide
Python 使用 PEP8 规范
JavaScript 使用 Standard Style
许可证
本项目采用 MIT 许可证 - 详见 LICENSE 文件

技术支持
遇到问题？请通过以下方式联系我们：

📧 邮箱：support@sysmonplus.com
💬 Slack 频道：https://sysmonplus.slack.com
🐞 提交 Issue
