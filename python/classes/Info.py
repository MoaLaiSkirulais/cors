class Info:

    def __init__(self):
        self.response = {
            "status": 200,
            "version": "01",
            "lastRelease": "10/08/2017",
            "uptime": 287,
            "email": "support@gmail.com",
        }

    def get(self):
        return self.response
