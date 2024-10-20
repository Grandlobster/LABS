from flask import Flask, render_template, request, redirect, url_for
import mysql.connector

app = Flask(__name__)

# Establishing connection with MySQL database
def connect_db():
    return mysql.connector.connect(
        host="localhost",
        user="newuser",       # Replace with your MySQL username
        password="12345",   # Replace with your MySQL password
        database="miniproject"       # Replace with your database name
    )

@app.route('/')
def index():
    connection = connect_db()
    cursor = connection.cursor()
    cursor.execute("SELECT * FROM employees")
    employees = cursor.fetchall()
    connection.close()
    return render_template('index.html', employees=employees)

@app.route('/add', methods=['POST'])
def add_employee():
    emp_name = request.form['emp_name']
    dept_id = request.form['dept_id']
    salary = request.form['salary']
    
    connection = connect_db()
    cursor = connection.cursor()
    sql = "INSERT INTO employees (emp_name, dept_id, salary) VALUES (%s, %s, %s)"
    val = (emp_name, dept_id, salary)
    cursor.execute(sql, val)
    connection.commit()
    connection.close()
    
    return redirect(url_for('index'))

@app.route('/update', methods=['POST'])
def update_employee():
    emp_id = request.form['emp_id']
    salary = request.form['salary']
    
    connection = connect_db()
    cursor = connection.cursor()
    sql = "UPDATE employees SET salary = %s WHERE emp_id = %s"
    val = (salary, emp_id)
    cursor.execute(sql, val)
    connection.commit()
    connection.close()
    
    return redirect(url_for('index'))

@app.route('/delete/<int:emp_id>')
def delete_employee(emp_id):
    connection = connect_db()
    cursor = connection.cursor()
    sql = "DELETE FROM employees WHERE emp_id = %s"
    val = (emp_id,)
    cursor.execute(sql, val)
    connection.commit()
    connection.close()
    
    return redirect(url_for('index'))

if __name__ == "__main__":
    app.run(debug=True)
