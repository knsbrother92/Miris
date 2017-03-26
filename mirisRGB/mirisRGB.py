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
    '''INSERT INTO mirisRGB (red, green, blue) VALUES (%d, %d, %d)''' % (int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3])))
cursor.commit()