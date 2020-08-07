import requests
import json 
"""
url='https://jsonmock.hackerrank.com/api/football_matches?'
parameter={'year':2011,'team1':'Barcelona'}
res=requests.get(url,params=parameter)
match=res.json()
#print(match)
#print(type(match))
#print(type(match['data'][0]['team1goals']))
sum_team1=0
for goals in match['data']:
    #print(goals)
    sum_team1+=int(goals['team1goals'])
#print(sum_team1)

url='https://jsonmock.hackerrank.com/api/football_matches?'
parameter={'year':2011,'team2':'Barcelona'}
res=requests.get(url,params=parameter)
match=res.json()
sum_team2=0
for goals in match['data']:
    sum_team2+=int(goals['team2goals'])
print(sum_team1+sum_team2)
#sum=0
#for i in match['data']:
#   sum+=match['data']['team1']
#print(sum)
#print(type(content))


url='https://jsonmock.hackerrank.com/api/football_competitions?'
parameter={'year':2011,'name':'UEFA Champions League'}
res=requests.get(url,params=parameter)
matches=res.json()
#print(res.json())
print(matches['data'])
"""

url='https://jsonmock.hackerrank.com/api/football_matches?'
parameter={'year':2011,'competition':'UEFA Champions League','team2':'chelsea'}
res=requests.get(url,params=parameter)
matches=res.json()
#print(res.json())
#print(matches['data'])
sum=0
for goals in matches['data']:
    sum+=int(goals['team2goals'])
print(sum)
