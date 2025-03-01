# backend/app/api.py
from flask import Flask, jsonify
from flask_cors import CORS
import requests

app = Flask(__name__)
CORS(app)

AGENT_ENDPOINT = "http://localhost:8080/metrics"

@app.route('/api/metrics')
def get_metrics():
    try:
        response = requests.get(AGENT_ENDPOINT)
        return jsonify(response.json())
    except Exception as e:
        return jsonify({"error": str(e)}), 500

@app.route('/api/alert', methods=['POST'])
def set_alert():
    # 实现报警配置逻辑
    pass
