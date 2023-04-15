import sqlite3
import time

class DbManager:

    def init(self, path0 = '', db0 = 'tarakans.db'):
        self.conn = sqlite3.connect(db0) # или :memory: чтобы сохранить в RAM
        self.cursor = self.conn.cursor()

    def commit(self):
        self.conn.commit()
        
    def execute(self, sql):
        return self.cursor.execute(s)