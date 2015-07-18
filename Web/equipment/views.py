# coding: utf8
import json
from django.http import HttpResponse, Http404
from django.core import serializers
from equipment.models import Equipment
from django.shortcuts import render_to_response

def getEquipment(request):
    equipment = Equipment.objects.all()
    data = serializers.serialize("json", equipment)
    return HttpResponse(data)

def home(request):
	return render_to_response("index.html")
