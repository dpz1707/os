from socket import *

# Specify the mail server and port number
mailserver = 'smtp.nyu.edu'
serverPort = 25

# Create socket and establish TCP connection with mailserver
clientSocket = socket(AF_INET, SOCK_STREAM)
clientSocket.connect((mailserver, serverPort))

# Receive the server's response
tcp_resp = clientSocket.recv(1024).decode()
print(tcp_resp)

# Send HELO command to begin SMTP handshake
heloCommand = 'HELO Alice\r\n'
clientSocket.send(heloCommand.encode())
helo_resp = clientSocket.recv(1024).decode()
print(helo_resp)

# Send MAIL FROM command and print response
mailFrom = 'MAIL FROM: <noreply@mail.brightspace.nyu.edu>\r\n'
clientSocket.send(mailFrom.encode())
mailFrom_resp = clientSocket.recv(1024).decode()
print(mailFrom_resp)

# Send RCPT TO command and print server response
rcptTo = 'RCPT TO: <dz2191@nyu.edu>\r\n'
clientSocket.send(rcptTo.encode())
rcpt_resp = clientSocket.recv(1024).decode()
print(rcpt_resp)

# Send DATA command and print server response
dataCommand = 'DATA\r\n'
clientSocket.send(dataCommand.encode())
data_resp = clientSocket.recv(1024).decode()
print(data_resp)

# Send email data (headers and message)
emailContent = 'Subject: CS3224_OS_F24_SecA - Updated Grade: Your grade for "Quiz_04" has been updated\r\n\r\nYour grade for "Quiz_04" has been updated. Your grade is: 0 / 5, F\r\n.\r\n'
clientSocket.send(emailContent.encode())
email_resp = clientSocket.recv(1024).decode()
print(email_resp)

# Send QUIT command and get server response
quitCommand = 'QUIT\r\n'
clientSocket.send(quitCommand.encode())
quit_resp = clientSocket.recv(1024).decode()
print(quit_resp)

# Close the socket
clientSocket.close()
