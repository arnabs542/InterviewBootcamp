import urllib
import re

#Failed password for root from 116.31.116.6 port 24214 ssh2
#Failed password for invalid user admin from 
#Failed password for invalid user <user> from

class LoginAttempt:
    def __init__(self, user, ip):
        self.user = user
        self.ip = ip

logins = {}
f = urllib.urlopen('file:///Users/skatoch/InterviewKickstarter/InterviewBootcamp/WebProgramming/test.txt')
for line in f:
  m = re.match(r'^Failed password for (?:invalid user)? (\w+) from (\d{1,3}\.\d{1,3}\.\d{1,3}\.\d{1,3}).*', line)
  if m:
    l = LoginAttempt(m.group(1), m.group(2))
    try:
      logins[m.group(2)].append(l)
    except:
      logins[m.group(2)] = [l]

out = sorted(logins.items(), key=lambda (k,v):len(v), reverse=True)
for item in out:
    print item[0]
  
    
