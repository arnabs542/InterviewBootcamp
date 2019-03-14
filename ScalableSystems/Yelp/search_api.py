'''
simple use of the Yelp search api
'''
import requests
import json

API_KEY='vS6SxxVM3DNzq8ec9t0RGY8B2rGXRIF0T_gbbEe9yrpyvzuijw42JzBhMralJrijtVWkLhmRgY0owvDwN4kLhzSWrI2GrULpbKH2IcqPlcnyLB_rkl4xDcYhW694XHYx'
CLIENT_ID='wpnkaEl73jhtWLHqVB0rMg'

def search():
    payload = {
               'term':'food',
               'location':'Sacramento, CA',
               'radius': 30,
               'limit': 10,
               'sort_by': 'review_count'
              }

    headers = {
        'Authorization': 'Bearer %s' % API_KEY,
    }

    r = requests.get('https://api.yelp.com/v3/businesses/search', params=payload, headers=headers)
    print(r.url)
    print(r.text)


if __name__ == '__main__':
    search()
