import pyodbc, sys

server = 'miris-server.database.windows.net'
database = 'miris-database'
username = 'miris-admin'
password = 'qwer1234!@#$'
driver = '{ODBC Driver 13 for SQL Server}'
cnxn = pyodbc.connect(
    'DRIVER=' + driver + ';PORT=1433;SERVER=' + server + ';PORT=1443;DATABASE=' + database + ';UID=' + username + ';PWD=' + password)
cursor = cnxn.cursor()
cursor.execute(
    '''INSERT INTO mirisRFID (rfid) VALUES ('%s')''' % sys.argv[1])
cursor.commit()
