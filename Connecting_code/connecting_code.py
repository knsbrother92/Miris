
from azure.storage.blob import BlockBlobService, ContentSettings
import sys, os
block_blob_service = BlockBlobService(account_name='miris',
                                      account_key='Oki2fkesXIPsAKQlxJdmJIFQI+r4WP1TYXXs8UWM1nMNbdLvkwPwmsgBgWGc2LQnyk9GVzfaIT4kNSL064968A==')
block_blob_service.create_blob_from_path(
    'images',
    sys.argv[1],
    '../image.jpg',
    content_settings=ContentSettings(content_type='image/jpg')
)
