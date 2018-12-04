import requests

def getWords(letters, parameters):
  return requests.get("http://localhost:3004/api/{}".format(letters),params={"mask":parameters}).json()["words"]


