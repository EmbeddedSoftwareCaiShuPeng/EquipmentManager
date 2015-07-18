# This is an auto-generated Django model module.
# You'll have to do the following manually to clean this up:
#     * Rearrange models' order
#     * Make sure each model has one field with primary_key=True
# Feel free to rename the models, but don't rename db_table values or field names.
#
# Also note: You'll have to insert the output of 'django-admin.py sqlcustom [appname]'
# into your database.
from __future__ import unicode_literals

from django.db import models

class Admin(models.Model):
    adminname = models.CharField(max_length=30L, db_column='adminName', blank=True) # Field name made lowercase.
    password = models.CharField(max_length=40L, blank=True)
    class Meta:
        db_table = 'Admin'

class Equipment(models.Model):
    id = models.CharField(max_length=50L, primary_key=True)
    name = models.CharField(max_length=100L, blank=True)
    type = models.CharField(max_length=100L, blank=True)
    state = models.CharField(max_length=30L, blank=True)
    class Meta:
        db_table = 'Equipment'

class Order(models.Model):
    id = models.IntegerField(primary_key=True)
    equipmentid = models.CharField(max_length=30L, db_column='equipmentId', blank=True) # Field name made lowercase.
    userid = models.CharField(max_length=30L, db_column='userId', blank=True) # Field name made lowercase.
    studentid = models.CharField(max_length=30L, db_column='studentId', blank=True) # Field name made lowercase.
    studentphone = models.CharField(max_length=20L, db_column='studentPhone', blank=True) # Field name made lowercase.
    date = models.DateTimeField()
    class Meta:
        db_table = 'Order_'

class T(models.Model):
    i = models.IntegerField(null=True, blank=True)
    d = models.DateField(null=True, blank=True)
    class Meta:
        db_table = 'T'

class User(models.Model):
    username = models.CharField(max_length=30L, primary_key=True, db_column='userName') # Field name made lowercase.
    password = models.CharField(max_length=30L, blank=True)
    studentid = models.CharField(max_length=50L, db_column='studentId', blank=True) # Field name made lowercase.
    studentphone = models.CharField(max_length=20L, db_column='studentPhone', blank=True) # Field name made lowercase.
    class Meta:
        db_table = 'User'

class Person(models.Model):
    number = models.IntegerField(null=True, blank=True)
    name = models.CharField(max_length=255L, blank=True)
    class Meta:
        db_table = 'person'

