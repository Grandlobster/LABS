from xmlrpc.server import SimpleXMLRPCServer
from functools import reduce

factorial= lambda n: reduce(lambda x,y: x*y, range(1,n+1),1)

server= SimpleXMLRPCServer(("localhost", 8000))
print("Server running")

server.register_function(factorial, "factorial")
server.serve_forever()

