#! /usr/bin/python

import time

class User
  def __init__(self, name, password):
      self.uname = name       # user name
      self.pwd = password     # password
      self.uid = generateId() # user id
      self.auth = None        # authentication token
      self.followers = []     # followers for this user
      self.following = []     # is this needed ??


class Tweet
  def __init__(self, uid, message, resourceid):
      self.uid = uid               # user id for the user who tweeted this 
      self.message = message       # text message
      self.resource = resourceid   # picture/video?
      self.timestamp = time.time() # time

class Timeline
  def __init__(self, uid):
      self.uid = uid          # This is a timeline for uid user
      self.tweets = []        # Tweet ids which form the timeline for user
