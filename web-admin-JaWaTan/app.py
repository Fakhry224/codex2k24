from flask import Flask, request, jsonify, make_response, render_template, session, redirect, url_for
from markupsafe import escape
from datetime import datetime, timedelta
from dotenv import load_dotenv
import jwt
import os

load_dotenv()

app = Flask(__name__)
app.config['FLAG'] = os.getenv('FLAG') or "CODEX2K24{F4K3_FL4G_D0NT_SUBM1T_IT}"

app.config['SECRET_KEY'] = "supersecretkey"

users = {
    "user": {
        "password": "userpassword",
        "role": "user"
    },
}

@app.route('/')
def public():
    if 'source' in request.args:
        return display_source_code()
    
    return render_template('index.html')

@app.route('/private')
def private():
    token = request.headers.get('Authorization')
    if not token:
        return make_response('Token is missing!', 401)
    
    try:
        decoded = jwt.decode(token, app.config['SECRET_KEY'], algorithms=["HS256"])
        return 'JWT is verified. Welcome to your private page!'
    except jwt.ExpiredSignatureError:
        return make_response('Token has expired!', 401)
    except jwt.InvalidTokenError:
        return make_response('Invalid token!', 401)

def generate_token(username):
    payload = {
        'username': username,
        'role': users[username]['role'],
        'exp': datetime.utcnow() + timedelta(minutes=1)
    }
    token = jwt.encode(payload, app.config['SECRET_KEY'], algorithm="HS256")
    return token

# Login route
@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == "GET":
        return render_template("login.html")
    
    username = request.form.get('username')
    password = request.form.get('password')
    
    if username == "admin":
        return make_response('Don\'t pretend to be an admin!', 403)

    if username in users and password == '123456':
        session['logged_in'] = True
        token = generate_token(username)
        
        return jsonify({'token': token})
    else:
        return make_response('Unable to verify', 403, {'WWW-Authenticate': 'Basic realm: "Authentication Failed"'})

# Logout route
@app.route('/logout')
def logout():
    session.pop('logged_in', None)
    return redirect(url_for('public'))

@app.route('/admin', methods=['GET'])
def admin():
    token = request.headers.get('Authorization')
    if not token:
        return make_response('Token is missing!', 401)

    try:
        decoded = jwt.decode(token, app.config['SECRET_KEY'], algorithms=["HS256"])
        
        if decoded['role'] == 'admin':
            return jsonify({"message": "Welcome Admin!", "flag": app.config['FLAG']})
        else:
            return make_response('You are not authorized!', 403)
    except jwt.ExpiredSignatureError:
        return make_response('Token has expired!', 401)
    except jwt.InvalidTokenError:
        return make_response('Invalid token!', 401)


def display_source_code():
    file_path = os.path.abspath(__file__)
    with open(file_path, 'r') as f:
        code = f.read()
        
    escaped_code = escape(code)
    
    return f"<pre><code>{escaped_code}</code></pre>"
        

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0')